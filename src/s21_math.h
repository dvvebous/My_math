#ifndef S21_MATH_H
#define S21_MATH_H

#define E_NUM 2.7182818284590452353602874713527
#define S21_PI 3.14159265358979323846
#define POSITIVE_INF_NUM 1.0 / 0.0
#define NEGATIVE_INF_NUM -1.0 / 0.0
#define NAN_NUM 0.0 / 0.0
#define EPS_NUM 1e-16
#define S21_IS_INF(x) (x == POSITIVE_INF_NUM || x == NEGATIVE_INF_NUM)
#define S21_IS_NAN(x) (x != x)

int s21_abs(int x);
long double s21_fabs(double x);
long double s21_pow_int(long double x, int n);
long double s21_asin(double x);
long double s21_acos(double x);
long double s21_atan(double x);
long double s21_ceil(double x);
long double s21_floor(double x);
long double s21_fmod(double x, double y);
long double s21_log(double x);
long double s21_pow(double base, double y);
long double s21_exp(double x);
long double s21_sin(double x);
int s21_is_pos_inf(double x);
int s21_is_neg_inf(double x);
int s21_isnan(double x);
long double s21_cos(double x);
int s21_findPower(double *x);
long double s21_sqrt(double x);
long double s21_tan(double x);
long double s21_fuctorial(long long int x);

#endif