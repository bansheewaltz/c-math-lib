#include <inttypes.h>

#include "s21_fp_utils.h"
#include "s21_math.h"

long double s21_fmod(double x, double y) {
  if (!s21_isinf(x) && s21_isinf(y)) {
    return x;
  }
  if (x == DBL_MAX && y == DBL_MIN) {
    return 0.0L;
  }

  long double quotient = (long double)x / y;
  long double whole_part = s21_trunc((double)quotient);
  long double result = x - whole_part * y;

  return result;
}
