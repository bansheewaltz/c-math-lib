#include "s21_utils.h"

long double s21_ceil(double x) {
  int tmp = (int)x;

  if ((x != S21_INF) && (x != -S21_INF) && (tmp != x)) {
    if (x > 0) {
      x = tmp;
    } else {
      x = tmp - 1;
    }
  }

  return x;
}
