#ifndef MACROS_H
#define MACROS_H

/* Utility Macros */
#define MIN(a, b) ((a) < (b) ? (a) : (b))
#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define ABS(x) ((x) < 0 ? -(x) : (x))

/* Debug Logging */
#ifdef ENABLE_DEBUG
#define DEBUG_LOG(fmt, ...) printf("[DEBUG] " fmt "\n", ##__VA_ARGS__)
#else
#define DEBUG_LOG(fmt, ...)
#endif

/* Bit Manipulation Macros */
#define SET_BIT(val, bit) ((val) |= (1U << (bit)))
#define CLEAR_BIT(val, bit) ((val) &= ~(1U << (bit)))
#define TOGGLE_BIT(val, bit) ((val) ^= (1U << (bit)))
#define CHECK_BIT(val, bit) (((val) >> (bit)) & 1U)

#endif /* MACROS_H */
