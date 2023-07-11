#include "s21_math.h"
#include <stdio.h>

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

long double s21_exp(double x) {
    long double res = 0;

    if (s21_isnan(x)) {
        res = NAN_NUM;
    } else if (s21_is_pos_inf(x)) {
        res = POSITIVE_INF_NUM;
    } else if (s21_is_neg_inf(x)) {
        res = 0.0;
    } else {
        long double q = 1;
        double x1 = s21_fabs(x);
       
       for (int i = 1; s21_fabs(q) > EPS_NUM && s21_fabs(res) < POSITIVE_INF_NUM; i++) {
            res += q;
            q *= x1 / i;
       }

       if (x < 0) 
           res = 1 / res;
    } 

    return res;
}

long double s21_floor(double x) {
    return (x == (long long int)x) ? x :
    (x > 0) ? (long double)(((long long int)x)) :
    (x < 0) ? (long double)((long long int)x) - 1 : 0;
}

long double s21_fmod(double x, double y)
{
  int n = x / y;
  double res = (double)x - n * (double)y;
  return res;
}

long double s21_cos(double x) {
    long double res = 0;

    if (!s21_isnan(x) && !s21_is_pos_inf(x) && !s21_is_neg_inf(x)) {
        long double q = 1;

        if (s21_fabs(x) > 2 * S21_PI) 
            x = x - 2 * S21_PI * ((int)(x / (2 * S21_PI)));

        for (int i = 1; s21_fabs(q) > EPS_NUM; i++) {
            res += q;
            q *= (-1) * (x * x) / ((2 * i) * (2 * i - 1));
        }
    } else {
        res = NAN_NUM;
    }

    return res;
}


long double s21_sin(double x)
{
    x = s21_fmod(x, 2 * S21_PI);
    long double result = 0;
    long double expression = x;
    int i = 1;
    while (i < 200)
    {
        result += expression;
        expression = expression * (-1) * (x*x) / ((2*i+1) * (2*i));
        i++;
    
}
    printf("%d\n", i);
	return result;
}


int s21_is_pos_inf(double x) {
    return x == POSITIVE_INF_NUM ? 1 : 0;
}

int s21_is_neg_inf(double x) {
    return x == NEGATIVE_INF_NUM ? 1 : 0;
}

int s21_isnan(double x) {
    return x == x ? 0 : 1;
}


int s21_findPower(double *x) {
    int n = 0;
    while (*x >= 2) {
        *x /= 2; 
        n++;
    }
    return n;
}


long double s21_log(double x) {
    long double res = 0;
    if (x < 0 || s21_isnan(x)) {
        res = NAN_NUM;
    } else if (x == 0) {
        res = NEGATIVE_INF_NUM;
    } else if (x == POSITIVE_INF_NUM) {
        res = POSITIVE_INF_NUM;
    } else {
        long double log2 = 0.693147180559945309;
        int n = s21_findPower(&x);
        double x1 = x - 1;
        long double q = x1;
        for (int i = 1; s21_fabs(q) > EPS_NUM; i++) {
            res += q;
            q *= (-1) * x1 * i / (i + 1);
        }
        res += n * log2;
    }

    return res;
}

long double s21_pow(double base, double y) {  
    long double result = 0;
    if (y == 0) result = 1.0L;
    else if (y > 0) result = s21_exp(y * s21_log(base));
    else
        result = 1 / (s21_exp(-y * s21_log(base)));
    return result;
}