#include "s21_fp_utilsl.h"
#include "s21_math.h"

long double s21_fabsl(long double x) {
  if (s21_isnanl(x)) {
    return S21_FP_NAN;
  }

  if (x < 0.0L) {
    return -x;
  }
  return x;
}
