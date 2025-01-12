#ifndef OTA_UPDATE_H
#define OTA_UPDATE_H

/* Function prototypes */
int ota_update_check(const char *server_url);
int ota_update_download(const char *update_url, const char *destination);
int ota_update_apply(const char *firmware_path);

#endif /* OTA_UPDATE_H */
