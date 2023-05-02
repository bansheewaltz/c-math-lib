#include <inttypes.h>

#include "s21_fp_utils.h"
#include "s21_math.h"

// long double s21_fmod(double x, double y) {
//   if (!s21_isinf(x) && s21_isinf(y)) {
//     return x;
//   }

//   double quotient = s21_trunc(x / y);
//   long double without_trace = y * quotient;
//   long double result = x - without_trace;

//   return result;
// }

long double s21_fmod(double x, double y) {
  if (s21_isnan(y)) {
    return S21_FP_NAN;
  }
  if (y == 0) {
    return S21_FP_NAN;
  }
  if (x == 0) {
    return 0;
  }
  if (s21_isninf(x) && s21_ispinf(y)) {
    return S21_FP_NAN;
  }
  if (s21_ispinf(x) && s21_ispinf(y)) {
    return S21_FP_NAN;
  }
  if (s21_isninf(x) && s21_isninf(y)) {
    return S21_FP_NAN;
  }
  if (s21_isinf(y)) {
    return x;
  }

  int64_t whole_part = x / y;
  long double result = (long double)x - whole_part * (long double)y;

  return result;
}
