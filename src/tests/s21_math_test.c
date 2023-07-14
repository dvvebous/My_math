#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <check.h>
#include "../s21_math.h"

#define int_1 NAN
#define int_2 -INFINITY
#define int_3 INFINITY

START_TEST(s21_abs_test) {
    ck_assert_int_eq(s21_abs(2), abs(2));
    ck_assert_int_eq(s21_abs(-1), abs(-1));
    ck_assert_int_eq(s21_abs(0), abs(0));

    ck_assert_int_eq(s21_abs((int)INFINITY),abs((int)INFINITY));
    ck_assert_int_eq(s21_abs((int)-INFINITY),abs((int)-INFINITY));
    ck_assert_int_eq(s21_abs((int)NAN),abs((int)NAN));
}
END_TEST



START_TEST(s21_acos_test) {
    ck_assert_ldouble_eq_tol(acos(0.6), s21_acos(0.6), 1e-6);
    ck_assert_ldouble_eq_tol(acos(-0.6), s21_acos(-0.6), 1e-6);
    ck_assert_ldouble_eq_tol(acos(0.0), s21_acos(0.0), 1e-6);
    ck_assert_ldouble_nan(s21_acos(5.0));
    ck_assert_ldouble_eq_tol(acos(1.0), s21_acos(1.0), 1e-6);

    ck_assert_ldouble_eq_tol(acos(-1), s21_acos(-1), 1e-6);
    ck_assert_ldouble_nan(s21_acos(int_1));
    ck_assert_ldouble_nan(s21_acos(int_2));
    ck_assert_ldouble_nan(s21_acos(int_3));

}
END_TEST

START_TEST(s21_asin_test) {
    ck_assert_ldouble_eq_tol(s21_asin(0.6), asin(0.6), 1e-6);
    ck_assert_ldouble_eq_tol(s21_asin(-0.6), asin(-0.6), 1e-6);
    ck_assert_ldouble_eq_tol(s21_asin(0.0), asin(0.0), 1e-6);
    ck_assert_ldouble_nan(s21_asin(5));
    ck_assert_ldouble_eq_tol(s21_asin(1), asin(1), 1e-6);

    ck_assert_ldouble_eq_tol(s21_asin(-1), asin(-1), 1e-6);
    ck_assert_ldouble_nan(s21_asin(int_1));
    ck_assert_ldouble_nan(s21_asin(int_2));
    ck_assert_ldouble_nan(s21_asin(int_3));

}
END_TEST

START_TEST(s21_atan_test) {
    ck_assert_ldouble_eq_tol(atan(0.6), s21_atan(0.6), 1e-6);
    ck_assert_ldouble_eq_tol(atan(-0.6), s21_atan(-0.6), 1e-6);
    ck_assert_ldouble_eq_tol(atan(0.0), s21_atan(0.0), 1e-6);
    ck_assert_ldouble_eq_tol(atan(5), s21_atan(5), 1e-6);
    ck_assert_ldouble_eq_tol(atan(1), s21_atan(1), 1e-6);

    ck_assert_ldouble_eq_tol(atan(-1), s21_atan(-1), 1e-6);
    ck_assert_ldouble_nan(s21_atan(int_1));
    ck_assert_ldouble_eq_tol(atan(int_2), s21_atan(int_2), 1e-6);
    ck_assert_ldouble_eq_tol(atan(int_3), s21_atan(int_3), 1e-6);

}
END_TEST

START_TEST(s21_ceil_test) {
    ck_assert_ldouble_eq(s21_ceil(-13.7), ceil(-13.7));
    ck_assert_ldouble_eq(s21_ceil(0.5), ceil(0.5));
    ck_assert_ldouble_eq(s21_ceil(2.56687), ceil(2.56687));
    ck_assert_ldouble_eq(s21_ceil(-134.98879), ceil(-134.98879));
    ck_assert_ldouble_eq(s21_ceil(1.0), ceil(1.0));
    ck_assert_ldouble_eq(s21_ceil(-5.0), ceil(-5.0));

    ck_assert_float_eq(isnan(s21_ceil(int_1)), isnan(ceil(int_1)));
    ck_assert_float_eq(s21_ceil(int_2), ceil(int_2));
}
END_TEST

START_TEST(s21_cos_test) {
    ck_assert_float_eq(s21_cos(-1.56), cos(-1.56));
    ck_assert_float_eq(s21_cos(0.0), cos(0.0));
    ck_assert_float_eq(s21_cos(3.14), cos(3.14));
    ck_assert_float_eq(s21_cos(0.657), cos(0.657));
    ck_assert_float_eq(s21_cos(-1.67), cos(-1.67));
    ck_assert_float_eq(s21_cos(22.3), cos(22.3));
    
    ck_assert_int_eq(s21_cos((int)INFINITY), cos((int)INFINITY));
    ck_assert_int_eq(s21_cos((int)-INFINITY), cos((int)-INFINITY));
    ck_assert_int_eq(s21_cos((int)NAN), cos((int)NAN));
}
END_TEST

START_TEST(s21_exp_test) {
    ck_assert_float_eq(s21_exp(-1.56), exp(-1.56));
    ck_assert_float_eq(s21_exp(0.0), exp(0.0));
    ck_assert_float_eq(s21_exp(3.14), exp(3.14));
    ck_assert_float_eq(s21_exp(0.657), exp(0.657));
    ck_assert_float_eq(s21_exp(-1.67), exp(-1.67));
    ck_assert_float_eq(s21_exp(22.3), exp(22.3));

    ck_assert_int_eq(s21_exp((int)INFINITY), exp((int)INFINITY));
    ck_assert_int_eq(s21_exp((int)-INFINITY), exp((int)-INFINITY));
    ck_assert_int_eq(s21_exp((int)NAN), exp((int)NAN));
}
END_TEST


START_TEST(s21_fabs_test) {
    ck_assert_double_eq(s21_fabs(-1.5),fabs(-1.5));
    ck_assert_double_eq(s21_fabs(0.0),fabs(0.0));
    ck_assert_double_eq(s21_fabs(0.5), fabs(0.5));
    ck_assert_double_eq(s21_fabs(1.17394757593),fabs(1.17394757593));
    ck_assert_double_eq(s21_fabs(36.5), fabs(36.5)); 

    ck_assert_float_eq(isnan(s21_fabs(int_1)), isnan(fabs(int_1)));
    ck_assert_float_eq(s21_fabs(int_2), fabs(int_2));
}
END_TEST


START_TEST(s21_floor_test) {
    ck_assert_ldouble_eq(s21_floor(-13.7), floor(-13.7));
    ck_assert_ldouble_eq(s21_floor(0.5), floor(0.5));
    ck_assert_ldouble_eq(s21_floor(2.56687), floor(2.56687));
    ck_assert_ldouble_eq(s21_floor(-134.98879), floor(-134.98879));
    ck_assert_ldouble_eq(s21_floor(1.0), floor(1.0));
    ck_assert_ldouble_eq(s21_floor(-5.0), floor(-5.0));

    ck_assert_ldouble_nan(s21_floor(int_1));
    ck_assert_ldouble_eq(s21_floor(int_2), floor(int_2));
    ck_assert_ldouble_eq(s21_floor(int_3), floor(int_3));
}
END_TEST

START_TEST(s21_fmod_test) {
    ck_assert_ldouble_eq(s21_fmod(-3.15, 2.5), fmod(-3.15, 2.5));
    ck_assert_ldouble_eq(s21_fmod(11.213, 1.5), fmod(11.213, 1.5));
    ck_assert_ldouble_eq_tol(s21_fmod(-1000.21313, 3.23), fmod(-1000.21313, 3.23), 1e-6);
    ck_assert_ldouble_eq(s21_fmod(34434.89898, 2.5), fmod(34434.89898, 2.5));
    ck_assert_ldouble_eq(s21_fmod(0, 2.5), fmod(0, 2.5));
    ck_assert_ldouble_eq(s21_fmod(2.5, 1.8), fmod(2.5, 1.8));

    ck_assert_int_eq(s21_fmod(int_1, int_1), fmod(int_1, int_1));
    ck_assert_int_eq(s21_fmod(int_2, int_2), fmod(int_2, int_2));
    ck_assert_int_eq(s21_fmod(int_1, int_2), fmod(int_1, int_2));
    ck_assert_int_eq(s21_fmod(int_2, int_3), fmod(int_2, int_3));
}
END_TEST


START_TEST(s21_log_test) {
    ck_assert_ldouble_nan(s21_log(-3.15));
    ck_assert_ldouble_eq_tol(s21_log(11.213), log(11.213), 1e-6);
    ck_assert_ldouble_nan(s21_log(-1000.21313));
    ck_assert_ldouble_eq_tol(s21_log(34434.89898), log(34434.89898), 1e-6);
    ck_assert_ldouble_eq(s21_log(0.0), log(0.0));
    ck_assert_ldouble_eq_tol(s21_log(2.5), log(2.5), 1e-6);

    ck_assert_int_eq(s21_log(int_1), log(int_1));
    ck_assert_int_eq(s21_log(int_2), log(int_2));
    ck_assert_int_eq(s21_log(int_2), log(int_3));
}
END_TEST

START_TEST(s21_pow_test) {
    ck_assert_float_eq(s21_fmod(-3.15, 2.5), fmod(-3.15, 2.5));
    ck_assert_float_eq(s21_fmod(11.213, 1.5), fmod(11.213, 1.5));
    ck_assert_int_eq(s21_fmod(-1000.21313, 3.23), fmod(-1000.21313, 3.23));
    ck_assert_float_eq(s21_fmod(34434.89898, 2.5), fmod(34434.89898, 2.5));
    ck_assert_float_eq(s21_fmod(0, 2.5), fmod(0, 2.5));
    ck_assert_float_eq(s21_fmod(2.5, 1.8), fmod(2.5, 1.8));

    ck_assert_int_eq(s21_pow(int_1, int_1), pow(int_1, int_1));
    ck_assert_int_eq(s21_pow(int_2, int_2), pow(int_2, int_2));
    ck_assert_int_eq(s21_pow(int_3, int_3), pow(int_3, int_3));
    ck_assert_int_eq(s21_pow(int_1, int_2), pow(int_1, int_2));
}
END_TEST

START_TEST(s21_sin_test) {
    ck_assert_float_eq(s21_sin(-1.56), sin(-1.56));
    ck_assert_float_eq(s21_sin(0.0), sin(0.0));
    ck_assert_float_eq(s21_sin(3.14), sin(3.14));
    ck_assert_float_eq(s21_sin(0.657), sin(0.657));
    ck_assert_float_eq(s21_sin(-1.67), sin(-1.67));
    ck_assert_float_eq(s21_sin(13.3), sin(13.3));

    ck_assert_int_eq(s21_sin(int_1), sin(int_1));
    ck_assert_int_eq(s21_sin(int_2), sin(int_2));
    ck_assert_int_eq(s21_sin(int_3), sin(int_3));
}
END_TEST

START_TEST(s21_sqrt_test) {
    ck_assert_ldouble_eq_tol(sqrt(0.0), s21_sqrt(0.0), 1e-6);
    ck_assert_ldouble_eq_tol(sqrt(1.0), s21_sqrt(1.0), 1e-6);
    ck_assert_ldouble_eq_tol(sqrt(3.14), s21_sqrt(3.14), 1e-6);
    ck_assert_ldouble_eq_tol(sqrt(6.28), s21_sqrt(6.28), 1e-6);
    ck_assert_ldouble_eq_tol(sqrt(2.2343), s21_sqrt(2.2343), 1e-6);
    ck_assert_int_eq(sqrt(-123), s21_sqrt(-123));

    ck_assert_int_eq(s21_log(int_1), log(int_1));
    ck_assert_int_eq(s21_log(int_2), log(int_2));
    ck_assert_int_eq(s21_log(int_2), log(int_3));
}
END_TEST

START_TEST(s21_tan_test) {
    ck_assert_float_eq(s21_tan(-1.56), tan(-1.56));
    ck_assert_float_eq(s21_tan(0.0), tan(0.0));
    ck_assert_float_eq(s21_tan(3.14), tan(3.14));
    ck_assert_float_eq(s21_tan(0.657), tan(0.657));
    ck_assert_float_eq(s21_tan(-1.67), tan(-1.67));
    ck_assert_float_eq(s21_tan(22.3), tan(22.3));
    
    ck_assert_int_eq(s21_tan((int)INFINITY),tan((int)INFINITY));
    ck_assert_int_eq(s21_tan((int)-INFINITY), tan((int)-INFINITY));
    ck_assert_int_eq(s21_tan((int)NAN), tan((int)NAN));
}
END_TEST


Suite *lib_suite(void) {
    Suite *s;
    s = suite_create("Checking functions");
    
    TCase *tc_asin;
    TCase *tc_acos;
    TCase *tc_atan;
    TCase *tc_tan;
    TCase *tc_abs;
    TCase *tc_fabs;
    TCase *tc_fmod;
    TCase *tc_log;
    TCase *tc_pow;
    TCase *tc_ceil;
    TCase *tc_cos;
    TCase *tc_exp;
    TCase *tc_sin;
    TCase *tc_floor;  
    TCase *tc_sqrt;

    tc_abs = tcase_create("S21_ABS");
    tc_acos = tcase_create("S21_ACOS");
    tc_asin = tcase_create("S21_ASIN");
    tc_atan = tcase_create("S21_ATAN");
    tc_ceil = tcase_create("S21_CEIL");
    tc_cos = tcase_create("S21_COS");
    tc_exp = tcase_create("S21_EXP");
    tc_fabs = tcase_create("S21_FABS");
    tc_floor = tcase_create("S21_FLOOR");
    tc_fmod = tcase_create("S21_FMOD");
    tc_log = tcase_create("S21_LOG");
    tc_pow = tcase_create("S21_POW");
    tc_sin = tcase_create("S21_SIN");
    tc_sqrt = tcase_create("S21_SQRT");
    tc_tan = tcase_create("S21_TAN");

    suite_add_tcase(s, tc_abs);
    tcase_add_test(tc_abs, s21_abs_test);

    suite_add_tcase(s, tc_acos);
    tcase_add_test(tc_acos, s21_acos_test);

    suite_add_tcase(s, tc_asin);
    tcase_add_test(tc_asin, s21_asin_test);

    suite_add_tcase(s, tc_atan);
    tcase_add_test(tc_atan, s21_atan_test);

    suite_add_tcase(s, tc_ceil);
    tcase_add_test(tc_ceil, s21_ceil_test);

    suite_add_tcase(s, tc_cos);
    tcase_add_test(tc_cos, s21_cos_test);

    suite_add_tcase(s, tc_exp);
    tcase_add_test(tc_exp, s21_exp_test);

    suite_add_tcase(s, tc_fabs);
    tcase_add_test(tc_fabs, s21_fabs_test);

    suite_add_tcase(s, tc_floor);
    tcase_add_test(tc_floor, s21_floor_test);

    suite_add_tcase(s, tc_fmod);
    tcase_add_test(tc_fmod, s21_fmod_test);

    suite_add_tcase(s, tc_log);
    tcase_add_test(tc_log, s21_log_test);

    suite_add_tcase(s, tc_pow);
    tcase_add_test(tc_pow, s21_pow_test);

    suite_add_tcase(s, tc_sin);
    tcase_add_test(tc_sin, s21_sin_test);

    suite_add_tcase(s, tc_sqrt);
    tcase_add_test(tc_sqrt, s21_sqrt_test);

    suite_add_tcase(s, tc_tan);
    tcase_add_test(tc_tan, s21_tan_test);

    return s;
}

int main(void) {
    Suite *s;
    SRunner *sr;

    s = lib_suite();
    sr = srunner_create(s);
    srunner_run_all(sr, CK_VERBOSE);
    srunner_free(sr);
    return 0;
}