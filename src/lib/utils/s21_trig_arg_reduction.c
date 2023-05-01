#include "s21_math.h"

double s21_trig_arg_reduction(double x) {
  if (x > S21_PI) {
    while (x > S21_PI) {
      x -= S21_PI * 2;
    }
  }
  if (x < -S21_PI) {
    while (x > S21_PI) {
      x += S21_PI * 2;
    }
  }

  return x;
}
