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
    long double rez = 1, y = 1;
    long double i = 1;
    int flag = 0;
    if (x < 0) {
        x *= -1;
        flag = 1;
    }
    while (s21_fabs(rez) > s21_EPS) {
    rez *= x / i;
        i++;
        y += rez;
        if (y > s21_MAX_double) {
            y = s21_INF;
            break;
        }
    }
    y = flag == 1 ? y > s21_MAX_double ? 0 : 1. / y : y;
    return y = y > s21_MAX_double ? s21_INF : y;
}

// long double s21_pow(double base, double exp) {
//     double res;
//     int i;

//     for (i = 1; i <= )
// }