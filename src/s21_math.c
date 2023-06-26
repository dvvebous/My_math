#include "s21_math.h"

int s21_abs (int x) {
    return (x < 0) ? -x : x;
}

long double s21_fabs(double x) {
    return (x < 0) ? -x : x;
}

long double s21_ceil(double x) {
    int count;
    double y = x < 0 ? -x : x;
    for (count = 0; count < y; count++) {
    }
    return x < 0 ? -count + 1 : count;
}

long double s21_floor(double x) {
    int count;
    double y = x < 0 ? -x : x;
    for (count = 0; count < y; count++) {        
    }
    return x < 0 ? -count : count - 1;
}

long double s21_exp(double x) {
    double result = 1.0;
    double term = 1.0;
    int i;

    for (i = 1; i <= 20; i++) {
        term *= x / i;
        result += term;
    }

    return result;
}

