#include "s21_math.h"

long double s21_trig_range_reduction(long double x) {
  if (x < -S21_PI || S21_PI < x) {
    return s21_fmod((double)x, (double)(S21_PI * 2));
  }

  return x;
}
