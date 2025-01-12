#include "lib.h"

double sqrt(double x) {
    if (x < 0) return -1; // Error for negative input
    double result = x, diff;
    do {
        double old = result;
        result = 0.5 * (result + x / result);
        diff = old - result;
    } while (diff > 1e-6 || diff < -1e-6); // Convergence threshold
    return result;
}

double pow(double base, double exp) {
    double result = 1.0;
    for (int i = 0; i < exp; i++) {
        result *= base;
    }
    return result;
}
