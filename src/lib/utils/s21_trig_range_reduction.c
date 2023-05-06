#include "s21_math.h"

double s21_trig_range_reduction(double x) {
  if (x > S21_PI || x < -S21_PI) {
    return (double)s21_fmod(x, (double)(S21_PI * 2));
  }

  return x;
}
