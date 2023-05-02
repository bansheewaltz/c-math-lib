#include <inttypes.h>

#include "s21_fp_utils.h"
#include "s21_math.h"

long double s21_fmod(double x, double y) {
  if (!s21_isinf(x) && s21_isinf(y)) {
    return x;
  }
  if (x == DBL_MAX && y == DBL_MIN) {
    return 0;
  }

  long double whole_part = s21_trunc(x / y);
  long double result = x - whole_part * y;

  return result;
}
