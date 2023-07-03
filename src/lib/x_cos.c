#include "sx_fp_utils.h"
#include "sx_fp_utilsl.h"
#include "sx_math.h"

// through Taylor series
long double sx_cos(double x) {
  if (sx_isnan(x)) {
    return Sx_FP_NAN;
  }
  if (sx_isinf(x)) {
    return Sx_FP_NAN;
  }

  long double inp = sx_trig_range_reduction((long double)x);

  long double ith_term = 1;  // 1 is the zeroth term
  long double partial_sum = ith_term;

  int i = 1;
  while (sx_fabsl(ith_term) > Sx_EPSILON) {
    ith_term = -ith_term * inp * inp / ((2 * i) * (2 * i - 1));
    partial_sum += ith_term;
    ++i;

    if (i >= LOOP_LIMIT) {
      break;
    }
  }

  return partial_sum;
}
