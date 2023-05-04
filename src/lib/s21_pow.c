#include "s21_fp_utils.h"
#include "s21_math.h"

bool are_theese_boundary_values(double base, double exp, long double *res);

long double s21_pow(double base, double exp) {
  long double res;
  if (are_theese_boundary_values(base, exp, &res)) {
    return res;  // NOLINT
  }

  int res_sign = 1;
  if (s21_isnegative(base)) {
    base = -base;
    if (s21_isint(exp) && !s21_iseven(exp)) {
      res_sign = -1;
    }
  }

  res = res_sign * s21_exp(exp * s21_log(base));

  return res;
}

// NOLINTNEXTLINE
bool are_theese_boundary_values(double base, double exp, long double *res) {
  bool values_are_boundary = true;

  if (base != 1.0 && s21_isnan(exp)) {
    *res = S21_FP_NAN;
  } else if (base == 1.0 || exp == 0.0) {
    *res = 1.0L;
  } else if (base == -1.0) {
    if (s21_isinf(exp)) {
      *res = 1.0L;
    } else if (s21_isint(exp) && s21_iseven(exp)) {
      *res = 1.0L;
    } else if (s21_isreal(exp)) {
      *res = S21_FP_NAN;
    } else {
      return false;
    }
  } else if (base == 0.0) {
    if (s21_ispositive(base) && exp < 0) {
      *res = S21_FP_PINF;
    } else if (s21_isnegative(base) && exp < 0) {
      if (s21_isint(exp) && s21_isodd(exp)) {
        *res = S21_FP_NINF;
      } else {
        *res = S21_FP_PINF;
      }
    } else if (s21_isnegative(base) && exp > 0) {
      *res = 0.0L;
    } else {
      return false;
    }
  } else if (base == S21_FP_NINF) {
    if (exp > 0.0) {
      if (s21_isint(exp) && s21_isodd(exp)) {
        *res = S21_FP_NINF;
      } else {
        *res = S21_FP_PINF;
      }
    } else {
      *res = 0.0L;
    }
  } else if (s21_isnegative(base) && s21_isreal(exp)) {
    *res = S21_FP_NAN;
  } else {
    values_are_boundary = false;
  }

  return values_are_boundary;
}
