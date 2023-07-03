#include "sx_fp_utils.h"
#include "sx_math.h"

static bool are_these_boundary_values(double base, double exp,
                                      long double *res);
static bool base_eq_zero_case(double base, double exp, long double *res);
static bool base_eq_one_neg_case(double exp, long double *res);
static bool base_eq_inf_neg_case(double exp, long double *res);

long double sx_pow(double base, double exp) {
  long double res = 0;

  if (are_these_boundary_values(base, exp, &res) == true) {
    return res;  // NOLINT
  }
  if (exp == -1.0) {
    return 1.0 / base;
  }
  if (exp == +1.0) {
    return base;
  }

  int res_sign = 1;
  if (sx_isnegative(base)) {
    base = -base;
    if (sx_isint(exp) && !sx_iseven(exp)) {
      res_sign = -1;
    }
  }

  res = res_sign * sx_exp((double)((long double)exp * sx_log(base)));

  return res;
}

static bool are_these_boundary_values(double base, double exp,
                                      long double *res) {
  bool values_are_boundary = true;

  if (base != 1.0 && sx_isnan(exp)) {  // NOLINT
    *res = Sx_FP_NAN;
  } else if (base == 1.0 || exp == 0.0) {
    *res = 1.0L;  // NOLINT
  } else if (base == -1.0) {
    if (base_eq_one_neg_case(exp, res) == false) {
      return false;
    }
  } else if (base == 0.0) {
    if (base_eq_zero_case(base, exp, res) == false) {
      return false;
    }
  } else if (base == Sx_FP_NINF) {
    base_eq_inf_neg_case(exp, res);
  } else if (sx_isnegative(base) && sx_isreal(exp)) {
    *res = Sx_FP_NAN;
  } else {
    values_are_boundary = false;
  }

  return values_are_boundary;
}

static bool base_eq_one_neg_case(double exp, long double *res) {
  if (sx_isinf(exp)) {  // NOLINT
    *res = 1.0L;         // NOLINT
  } else if (sx_isint(exp) && sx_iseven(exp)) {
    *res = 1.0L;  // NOLINT
  } else if (sx_isreal(exp)) {
    *res = Sx_FP_NAN;
  } else {
    return false;
  }

  return true;
}

static bool base_eq_zero_case(double base, double exp, long double *res) {
  if (sx_ispositive(base) && exp < 0) {
    *res = Sx_FP_PINF;
  } else if (sx_isnegative(base) && exp < 0) {
    if (sx_isint(exp) && sx_isodd(exp)) {
      *res = Sx_FP_NINF;
    } else {
      *res = Sx_FP_PINF;
    }
  } else if (sx_isnegative(base) && exp > 0) {
    *res = 0.0L;
  } else {
    return false;
  }

  return true;
}

static bool base_eq_inf_neg_case(double exp, long double *res) {
  if (exp > 0.0) {
    if (sx_isint(exp) && sx_isodd(exp)) {
      *res = Sx_FP_NINF;
    } else {
      *res = Sx_FP_PINF;
    }
  } else {
    *res = 0.0L;
  }

  return true;
}
