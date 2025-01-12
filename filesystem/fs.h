#ifndef FS_H
#define FS_H

#include "stdio.h"
#include "string.h"
#include "esp_err.h"
#include "esp_err.h"
#include "esp_vfs.h"
#include "esp_vfs_fat.h"
#include "esp_spiffs.h"

/* File system API */
esp_err_t fs_init(void);
void fs_deinit(void);
esp_err_t fs_write_file(const char *path, const char *data);
esp_err_t fs_read_file(const char *path, char *buffer, size_t max_len);
esp_err_t fs_delete_file(const char *path);
esp_err_t fs_list_files(void);

#endif /* FS_H */
