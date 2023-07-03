#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#include "s21_math.h"

#define COLOR_RED   "\x1b[31m"
#define COLOR_GREEN "\x1b[32m"
#define COLOR_RESET "\x1b[0m"

void print_result(const char* message, int result) {
    if (result) {
        printf(COLOR_GREEN "%s: Passed\n" COLOR_RESET, message);
    } else {
        printf(COLOR_RED "%s: Failed\n" COLOR_RESET, message);
    }
}

void test_abs(int x) {
    int expected = abs(x);
    int result = s21_abs(x);
    printf("s21_abs(%d): %d\n", x, result);
    printf("Expected: %d\n", expected);
    print_result("Result matches expected", expected == result);
    printf("\n");
}

void test_fabs(double x) {
    double expected = fabs(x);
    double result = s21_fabs(x);
    printf("s21_fabs(%.2f): %.2f\n", x, result);
    printf("Expected: %.2f\n", expected);
    print_result("Result matches expected", expected == result);
    printf("\n");
}

void test_ceil(double x) {
    double expected = ceil(x);
    double result = s21_ceil(x);
    printf("s21_ceil(%.2f): %.2f\n", x, result);
    printf("Expected: %.2f\n", expected);
    print_result("Result matches expected", expected == result);
    printf("\n");
}

void test_floor(double x) {
    double expected = floor(x);
    double result = s21_floor(x);
    printf("s21_floor(%.2f): %.2f\n", x, result);
    printf("Expected: %.2f\n", expected);
    print_result("Result matches expected", expected == result);
    printf("\n");
}

int main() {
    test_abs(-5);
    test_abs(10);
    test_abs(1.32);
    test_abs(0);

    test_fabs(-2.5);
    test_fabs(5.75);
    test_fabs(-0);
    test_fabs(23);

    test_ceil(3.2);
    test_ceil(-4.8);
    test_ceil(1.2);
    test_ceil(0);

    test_floor(5.7);
    test_floor(-2.3);
    test_floor(1.7);
    test_floor(0);

    return 0;
}
