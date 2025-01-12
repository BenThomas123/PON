#include "security.h"
#include <stdio.h>
#include <string.h>

/* Predefined credentials for simplicity */
static const char *valid_username = "admin";
static const char *valid_password = "password123";

/* Authenticate a user based on username and password */
int authenticate_user(const char *username, const char *password) {
    if (strcmp(username, valid_username) == 0 && strcmp(password, valid_password) == 0) {
        printf("Authentication successful for user: %s\n", username);
        return 0; // Success
    }
    printf("Authentication failed for user: %s\n", username);
    return -1; // Failure
}
