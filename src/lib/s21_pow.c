// #include "./utils/s21_fp_utils.h"
// #include "./include/s21_math.h"

// #include <stdio.h>
// #include <math.h>

#include "s21_fp_utils.h"
#include "s21_math.h"

long double s21_pow(double base, double exp) {
  long double y = 0;
  int sight = 1;
  int exp_temp = exp;
  if (base == 0 && exp < 0) {
    y = S21_FP_PINF;
  } else if (base == 0 && exp > 0) {
    y = 0;
  } else if ((base == 0 && exp == 0) || base == 1) {
    y = 1;
  } else if (base != base || exp != exp ||
             (base < 0 &&
              exp - exp_temp != 0)) {  // Проверка на NAN сделать функцию
    y = S21_FP_NAN;
  } else {
    if (base < 0) {
      base = -base;
      if ((exp - exp_temp == 0) && exp_temp % 2 != 0) sight = -1;
    }
    y = sight * s21_exp(exp * s21_log(base));
  }
  return y;
}

// int main(){
//     double x = 0;
//     double y = 0;
//     scanf("%lf", &x);
//     scanf("%lf", &y);
//     printf("x = %lf, y = %lf, s21_pow = %Lf\n", x, y, s21_pow(x, y));
//     printf("x = %lf, y = %lf,     pow = %f\n", x, y, pow(x, y));
//     return 0;
// }