// #include "./utils/s21_fp_utils.h"
// #include "./include/s21_math.h"

// #include <stdio.h>
// #include <math.h>

#include "s21_fp_utils.h"
#include "s21_math.h"

long double s21_sqrt(double x) {
  long double y = x;
  long double y_temp = 1;
  if (x < 0) {
    y = -S21_FP_NAN;
  } else if (x == S21_FP_PINF) {
    y = S21_FP_PINF;
  } else if (x > 0) {
    // Пока превышает эпсилон вычисляем значение
    while ((y_temp - y) || (y - y_temp) > S21_EPSILON) {
      y = y_temp;
      y_temp = (y_temp + (x / y_temp)) / 2;
    }
  }
  return y;
}

// int main(){
//     double x = 0;
//     scanf("%lf", &x);
//     printf("x = %lf, s21_sqrt = %Lf\n", x, s21_sqrt(x));
//     printf("x = %lf,     sqrt = %f\n", x, sqrt(x));
//     return 0;
// }