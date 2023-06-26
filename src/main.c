#include <stdio.h>
#include "s21_math.h"
#include <math.h>

int main () {
    // int a = 0;
    // int res = s21_abs(a);
    // printf("%d\n", res);

    double b = 30;
    double res = s21_exp(b);
    printf("%lf\n", res);
    printf("%lf\n", exp(b));

    return 0;
}

