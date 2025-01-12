#include "fs.h"

/* Define the base path for the file system */
#define FS_BASE_PATH "/fs"

/* File system configuration */
#define FS_PARTITION_LABEL "storage"
#define FS_MAX_FILES 5 // Maximum number of open files
#define FS_MOUNT_POINT FS_BASE_PATH

/* Initialize the file system */
esp_err_t fs_init(void) {
    esp_vfs_spiffs_conf_t conf = {
        .base_path = FS_MOUNT_POINT,
        .partition_label = FS_PARTITION_LABEL,
        .max_files = FS_MAX_FILES,
        .format_if_mount_failed = true,
    };

    // Initialize SPIFFS
    esp_err_t ret = esp_vfs_spiffs_register(&conf);

    if (ret != ESP_OK) {
        if (ret == ESP_FAIL) {
            printf("Failed to mount or format filesystem\n");
        } else if (ret == ESP_ERR_NOT_FOUND) {
            printf("Failed to find SPIFFS partition\n");
        } else {
            printf("Failed to initialize SPIFFS (%s)\n", esp_err_to_name(ret));
        }
        return ret;
    }

    // Get partition information
    size_t total = 0, used = 0;
    ret = esp_spiffs_info(FS_PARTITION_LABEL, &total, &used);
    if (ret != ESP_OK) {
        printf("Failed to get SPIFFS partition info (%s)\n", esp_err_to_name(ret));
        return ret;
    }

    printf("SPIFFS initialized: Total=%d KB, Used=%d KB\n", total / 1024, used / 1024);
    return ESP_OK;
}

/* Deinitialize the file system */
void fs_deinit(void) {
    esp_vfs_spiffs_unregister(FS_PARTITION_LABEL);
    printf("SPIFFS unmounted\n");
}

/* Write data to a file */
esp_err_t fs_write_file(const char *path, const char *data) {
    char full_path[128];
    snprintf(full_path, sizeof(full_path), "%s/%s", FS_BASE_PATH, path);

    FILE *f = fopen(full_path, "w");
    if (f == NULL) {
        printf("Failed to open file for writing: %s\n", full_path);
        return ESP_FAIL;
    }

    fprintf(f, "%s", data);
    fclose(f);
    printf("File written: %s\n", full_path);
    return ESP_OK;
}

/* Read data from a file */
esp_err_t fs_read_file(const char *path, char *buffer, size_t max_len) {
    char full_path[128];
    snprintf(full_path, sizeof(full_path), "%s/%s", FS_BASE_PATH, path);

    FILE *f = fopen(full_path, "r");
    if (f == NULL) {
        printf("Failed to open file for reading: %s\n", full_path);
        return ESP_FAIL;
    }

    size_t len = fread(buffer, 1, max_len - 1, f);
    buffer[len] = '\0'; // Null-terminate the string
    fclose(f);

    printf("File read: %s, Data: %s\n", full_path, buffer);
    return ESP_OK;
}

/* Delete a file */
esp_err_t fs_delete_file(const char *path) {
    char full_path[128];
    snprintf(full_path, sizeof(full_path), "%s/%s", FS_BASE_PATH, path);

    if (remove(full_path) != 0) {
        printf("Failed to delete file: %s\n", full_path);
        return ESP_FAIL;
    }

    printf("File deleted: %s\n", full_path);
    return ESP_OK;
}

/* List files in the file system */
esp_err_t fs_list_files(void) {
    DIR *dir = opendir(FS_BASE_PATH);
    if (dir == NULL) {
        printf("Failed to open directory: %s\n", FS_BASE_PATH);
        return ESP_FAIL;
    }

    printf("Files in %s:\n", FS_BASE_PATH);
    struct dirent *entry;
    while ((entry = readdir(dir)) != NULL) {
        printf("  %s\n", entry->d_name);
    }

    closedir(dir);
    return ESP_OK;
}
