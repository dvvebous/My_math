#include "s21_math.h"
#include <stdio.h>

int s21_abs (int x) {
    return (x < 0) ? -x : x;
}

long double s21_fabs(double x) {
    return (x < 0) ? -x : x;
}


long double s21_ceil(double x) {
  long double result = 0, number = 1;
  if (S21_IS_INF(x) == 1 || S21_IS_NAN(x) == 1) {
    result = x;
  } else if (x < 0) {
    while (x <= -1) {
      number = -1;
      while (x <= number) {
        number *= 10;
      }
      if (number != -1) {
        number /= 10;
        result += number;
      }
      x -= number;
    }
  } else if (x == 0) {
    result = 0;
  } else {
    while (x >= 1) {
      number = 1;
      while (x > number) {
        number *= 10;
      }
      if (number != 1) {
        number /= 10;
        result += number;
      }
      x -= number;
    }
    result += 1;
  }
  return result;
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
  long double result = 0, number = 1;
  if (S21_IS_INF(x) == 1 || S21_IS_NAN(x) == 1) {
    result = x;
  } else if (x < 0) {
    while (x <= -1) {
      number = -1;
      while (x < number) {
        number *= 10;
      }
      if (number != -1) {
        number /= 10;
        result += number;
      }
      x -= number;
    }
    result -= 1;
  } else {
    while (x >= 1) {
      number = 1;
      while (x >= number) {
        number *= 10;
      }
      if (number != 1) {
        number /= 10;
        result += number;
      }
      x -= number;
    }
  }
  return result;
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

long double s21_pow(double base, double exp) {
    if (!exp) return 1;
    if (base == NEGATIVE_INF_NUM && exp == NEGATIVE_INF_NUM) return 0;
    if (base == NEGATIVE_INF_NUM && exp == POSITIVE_INF_NUM) return POSITIVE_INF_NUM;
    if (base < 0 && exp != (long long int)exp) return NAN_NUM;
    long double res = 0;
    int sign = base < 0 ? -1 : 1;
    res = s21_exp(exp * s21_log(base * sign));
    if (s21_fmod(exp, 2)) res *= sign;
    return res;
}

long double s21_sqrt(double x) {
  if (S21_IS_NAN(x) || x == NEGATIVE_INF_NUM || x < 0) return NAN_NUM;
  if (x == POSITIVE_INF_NUM || x == 0) return (long double)x;
  return s21_pow(x, 0.5);
}