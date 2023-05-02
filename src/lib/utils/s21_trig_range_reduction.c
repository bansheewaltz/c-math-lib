#include "s21_math.h"

double s21_trig_range_reduction(double x) {
  if (x > S21_PI || x < -S21_PI) {
    return s21_fmod(x, 2 * S21_PI);
  }

  return x;
}
