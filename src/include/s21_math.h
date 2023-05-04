#ifndef INCLUDE_S21_MATH_H_
#define INCLUDE_S21_MATH_H_

#include <float.h>

#define S21_FP_MAX LDBL_MAX
#define S21_FP_MIN LDBL_MIN
#define S21_EPSILON LDBL_EPSILON

#define S21_FP_PINF (1.0 / 0.0)
#define S21_FP_NINF (-1.0 / 0.0)
#define S21_FP_NAN (0.0 / 0.0)

#define S21_E 2.71828182845904523536028747135266250L
#define S21_PI 3.14159265358979323846264338327950288L
#define S21_PI_2 1.57079632679489661923132169163975144L
#define S21_PI_4 0.785398163397448309615660845819875721L

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
