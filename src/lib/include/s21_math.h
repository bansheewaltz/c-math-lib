#ifndef INCLUDE_S21_MATH_H_
#define INCLUDE_S21_MATH_H_

#define S21_E 2.71828182845904523536028747135266250
#define S21_PI 3.14159265358979323846264338327950288
#define S21_NAN 0.0 / 0.0
#define S21_INFINITY 1.0 / 0.0

/* absolute value */
int s21_abs(int x);
long double s21_fabs(double x);
/* modulo operation */
long double s21_fmod(double x, double y);
/* rounding */
long double s21_ceil(double x);
long double s21_floor(double x);
/* trigonometric */
long double s21_sin(double x);
long double s21_cos(double x);
long double s21_tan(double x);
/* inverse trigonometric */
long double s21_asin(double x);
long double s21_acos(double x);
long double s21_atan(double x);
/* other transcendental */
long double s21_pow(double base, double exp);
long double s21_sqrt(double x);
long double s21_exp(double x);
long double s21_log(double x);

#endif  // INCLUDE_S21_MATH_H_
