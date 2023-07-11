#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <check.h>
#include "s21_math.h"

START_TEST(s21_abs_test) {
    ck_assert_int_eq(s21_abs(2), abs(2));
    ck_assert_int_eq(s21_abs(-1), abs(-1));
    ck_assert_int_eq(s21_abs(0), abs(0));
    ck_assert_int_eq(s21_abs((int)INFINITY),abs((int)INFINITY));
    ck_assert_int_eq(s21_abs((int)-INFINITY),abs((int)-INFINITY));
    ck_assert_int_eq(s21_abs((int)NAN),abs((int)NAN));
}
END_TEST



// START_TEST(s21_acos_test) {

// }
// END_TEST

// START_TEST(s21_asin_test) {

// }
// END_TEST

// START_TEST(s21_atan_test) {

// }
// END_TEST

START_TEST(s21_ceil_test) {
    ck_assert_ldouble_eq(s21_ceil(-13.7), ceil(-13.7));
    ck_assert_ldouble_eq(s21_ceil(0.5), ceil(0.5));
    ck_assert_ldouble_eq(s21_ceil(2.56687), ceil(2.56687));
    ck_assert_ldouble_eq(s21_ceil(-134.98879), ceil(-134.98879));
    ck_assert_ldouble_eq(s21_ceil(1.0), ceil(1.0));
}
END_TEST

START_TEST(s21_cos_test) {
    ck_assert_float_eq(s21_cos(-1.56), cos(-1.56));
    ck_assert_float_eq(s21_cos(0.0), cos(0.0));
    ck_assert_float_eq(s21_cos(3.14), cos(3.14));
    ck_assert_float_eq(s21_cos(0.657), cos(0.657));
    ck_assert_float_eq(s21_cos(-1.67), cos(-1.67));
    ck_assert_float_eq(s21_cos(22.3), cos(22.3));
}
END_TEST

START_TEST(s21_exp_test) {
    ck_assert_float_eq(s21_exp(-1.56), exp(-1.56));
    ck_assert_float_eq(s21_exp(0.0), exp(0.0));
    ck_assert_float_eq(s21_exp(3.14), exp(3.14));
    ck_assert_float_eq(s21_exp(0.657), exp(0.657));
    ck_assert_float_eq(s21_exp(-1.67), exp(-1.67));
    ck_assert_float_eq(s21_exp(22.3), exp(22.3));
}
END_TEST


START_TEST(s21_fabs_test) {
    ck_assert_int_eq(s21_fabs(-1.5),fabs(-1.5));
    ck_assert_int_eq(s21_fabs(0.0),fabs(0.0));
    ck_assert_int_eq(s21_fabs(0.5), fabs(0.5));
    ck_assert_int_eq(s21_fabs(1.17394757593),fabs(1.17394757593));
    ck_assert_int_eq(s21_fabs(36.5), fabs(36.5));
}
END_TEST

START_TEST(s21_floor_test) {
    ck_assert_ldouble_eq(s21_floor(-13.7), floor(-13.7));
    ck_assert_ldouble_eq(s21_floor(0.5), floor(0.5));
    ck_assert_ldouble_eq(s21_floor(2.56687), floor(2.56687));
    ck_assert_ldouble_eq(s21_floor(-134.98879), floor(-134.98879));
    ck_assert_ldouble_eq(s21_floor(1.0), floor(1.0));
}
END_TEST

START_TEST(s21_fmod_test) {
    ck_assert_ldouble_eq(s21_fmod(-3.15, 2.5), fmod(-3.15, 2.5));
    ck_assert_ldouble_eq(s21_fmod(11.213, 1.5), fmod(11.213, 1.5));
    ck_assert_int_eq(s21_fmod(-1000.21313, 3.23), fmod(-1000.21313, 3.23));
    ck_assert_ldouble_eq(s21_fmod(34434.89898, 2.5), fmod(34434.89898, 2.5));
    ck_assert_ldouble_eq(s21_fmod(0, 2.5), fmod(0, 2.5));
    ck_assert_ldouble_eq(s21_fmod(2.5, 1.8), fmod(2.5, 1.8));
}
END_TEST


START_TEST(s21_log_test) {
    ck_assert_int_eq(s21_log(-3.15), log(-3.15));
    ck_assert_float_eq(s21_log(11.213), log(11.213));
    ck_assert_int_eq(s21_log(-1000.21313), log(-1000.21313));
    ck_assert_float_eq(s21_log(34434.89898), log(34434.89898));
    ck_assert_ldouble_eq(s21_log(0.0), log(0.0));
    ck_assert_float_eq(s21_log(2.5), log(2.5));
}
END_TEST

START_TEST(s21_pow_test) {
    ck_assert_float_eq(s21_fmod(-3.15, 2.5), fmod(-3.15, 2.5));
    ck_assert_float_eq(s21_fmod(11.213, 1.5), fmod(11.213, 1.5));
    ck_assert_int_eq(s21_fmod(-1000.21313, 3.23), fmod(-1000.21313, 3.23));
    ck_assert_float_eq(s21_fmod(34434.89898, 2.5), fmod(34434.89898, 2.5));
    ck_assert_float_eq(s21_fmod(0, 2.5), fmod(0, 2.5));
    ck_assert_float_eq(s21_fmod(2.5, 1.8), fmod(2.5, 1.8));
}
END_TEST

START_TEST(s21_sin_test) {
    ck_assert_float_eq(s21_sin(-1.56), sin(-1.56));
    ck_assert_float_eq(s21_sin(0.0), sin(0.0));
    ck_assert_float_eq(s21_sin(3.14), sin(3.14));
    ck_assert_float_eq(s21_sin(0.657), sin(0.657));
    ck_assert_float_eq(s21_sin(-1.67), sin(-1.67));
    ck_assert_float_eq(s21_sin(13.3), sin(13.3));
}
END_TEST

// START_TEST(s21_sqrt_test) {

// }
// END_TEST

// START_TEST(s21_tan_test) {

// }
// END_TEST


Suite *lib_suite(void) {
    Suite *s;
    s = suite_create("Checking functions");

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

    tc_abs = tcase_create("S21_ABS");
    // tc_acos = tcase_create("S21_ACOS");
    // tc_asin = tcase_create("S21_ASIN");
    // tc_atan = tcase_create("S21_ATAN");
    tc_ceil = tcase_create("S21_CEIL");
    tc_cos = tcase_create("S21_COS");
    tc_exp = tcase_create("S21_EXP");
    tc_fabs = tcase_create("S21_FABS");
    tc_floor = tcase_create("S21_FLOOR");
    tc_fmod = tcase_create("S21_FMOD");
    tc_log = tcase_create("S21_LOG");
    tc_pow = tcase_create("S21_POW");
    tc_sin = tcase_create("S21_SIN");
    // tc_sqrt = tcase_create("S21_SQRT");
    // tc_tan = tcase_create("S21_TAN");

    suite_add_tcase(s, tc_abs);
    tcase_add_test(tc_abs, s21_abs_test);

    // suite_add_tcase(s, tc_acos);
    // tcase_add_test(tc_acos, s21_acos_test);

    // suite_add_tcase(s, tc_asin);
    // tcase_add_test(tc_asin, s21_asin_test);

    // suite_add_tcase(s, tc_atan);
    // tcase_add_test(tc_asin, s21_asin_test);

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

    // suite_add_tcase(s, tc_sqrt);
    // tcase_add_test(tc_sqrt, s21_sqrt_test);

    // suite_add_tcase(s, tc_tan);
    // tcase_add_test(tc_tan, s21_tan_test);

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