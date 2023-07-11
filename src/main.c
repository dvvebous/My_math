#include <stdio.h>
#include "s21_math.h"
#include <math.h>
#include <stdlib.h>

int main () {


    int b = -3;
    int pes = abs(b);
    int res = s21_abs(b);
    printf("%d\n", res);
    printf("%d\n", pes);

    return 0;
}

