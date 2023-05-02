#ifndef S21_UTILS_H_
#define S21_UTILS_H_

#include <stdbool.h>
#include <stddef.h>

long double s21_factorial(int x);
bool s21_isfp(double x);
bool s21_isint(double x);
bool s21_isnan(double x);
bool s21_isinf(double x);
bool s21_ispinf(double x);
bool s21_isninf(double x);
void s21_print_bits(size_t size, void* ptr);
double s21_trig_range_reduction(double x);
long double s21_trunc(double x);

#endif  // S21_UTILS_H_
