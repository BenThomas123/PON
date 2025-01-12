#ifndef ERRORS_H
#define ERRORS_H

/* Error Codes */
#define ERR_OK 0               /* No error */
#define ERR_INVALID_ARG -1     /* Invalid argument */
#define ERR_OUT_OF_MEMORY -2   /* Memory allocation failure */
#define ERR_FILE_NOT_FOUND -3  /* File not found */
#define ERR_TIMEOUT -4         /* Operation timeout */
#define ERR_PERMISSION_DENIED -5 /* Permission denied */

/* Error Descriptions */
static const char *error_descriptions[] = {
    [ERR_OK] = "No error",
    [ERR_INVALID_ARG] = "Invalid argument",
    [ERR_OUT_OF_MEMORY] = "Out of memory",
    [ERR_FILE_NOT_FOUND] = "File not found",
    [ERR_TIMEOUT] = "Operation timeout",
    [ERR_PERMISSION_DENIED] = "Permission denied",
};

#endif /* ERRORS_H */
