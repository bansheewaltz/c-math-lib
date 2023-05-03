// #include "./utils/s21_fp_utils.h"
// #include "./include/s21_math.h"

// #include <stdio.h>
// #include <math.h>

#include "s21_fp_utils.h"
#include "s21_math.h"

long double s21_log(double x) {
  long double y = 0;
  if (x < 0 || x != x) {
    y = S21_FP_NAN;
  } else if (x == 0) {
    y = -S21_FP_PINF;
  } else if (x == S21_FP_PINF) {
    y = S21_FP_PINF;
  } else if (x < 1) {
    long double rez_temp = 1;
    long double rez = 1;
    int i = 1;
    int i_sight = 1;
    while (rez || -rez > S21_EPSILON) {
      if (i % 2 == 0) {
        i_sight = -1;
      } else {
        i_sight = 1;
      }
      rez_temp = rez_temp * (x - 1);
      rez = i_sight * rez_temp / i;
      y += rez;
      i++;
    }
  } else {
    long double rez = 1;
    int i = 0;
    while (i < 1000) {  //????????????
      rez = 2 * (x - s21_exp(y)) / (x + s21_exp(y));
      y += rez;
      i++;
    }
  }
  return y;
}

// int main(){
//     double x = 0;
//     scanf("%lf", &x);
//     printf("x = %lf, s21_log = %Lf\n", x, s21_log(x));
//     printf("x = %lf,     log = %f\n", x, log(x));
//     return 0;
// }
