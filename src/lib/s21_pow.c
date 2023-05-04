#include "s21_fp_utils.h"
#include "s21_math.h"

long double s21_pow(double base, double exp) {
  if (base == 1.0 || exp == 0.0) {
    return 1.0L;
  }
  if (base == -1.0) {
    if (s21_isinf(exp)) {
      return 1.0L;
    }
    if (s21_fabs(exp) == DBL_MAX) {
      return 1.0L;
    }
  }
  if (base == 0.0) {
    if (s21_ispositive(base) && exp < 0) {
      return S21_FP_PINF;
    }

    if (s21_isnegative(base) && exp < 0) {
      if (s21_isint(exp) && s21_isodd(exp)) {
        return S21_FP_NINF;
      }
      return S21_FP_PINF;
    }
    if (s21_isnegative(base) && exp > 0) {
      return 0.0L;
    }
  }
  if (base == S21_FP_NINF) {
    if (exp > 0.0) {
      if (s21_isodd(exp)) {
        return S21_FP_NINF;
      }
      return S21_FP_PINF;
    }
    if (exp < 0.0) {
      return 0.0L;
    }
  }
  if (s21_isnegative(base) && s21_isreal(exp)) {
    return S21_FP_NAN;
  }

  int sign = 1;
  if (s21_isnegative(base)) {
    base = -base;
    if (s21_isint(exp) && !s21_iseven(exp)) {
      sign = -1;
    }
  }

  long double res = sign * s21_exp(exp * s21_log(base));

  return res;
}
