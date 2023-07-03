#include "sx_fp_utils.h"
#include "sx_math.h"

// through Taylor series
long double sx_atan(double x) {
  if (x == 1.0) {
    return Sx_PI_4;
  }
  if (x == -1.0) {
    return -Sx_PI_4;
  }

  long double ith_term = 0;
  long double partial_sum = 0;

  if (-1.0 < x && x < 1.0) {
    ith_term = x;  // x is the zeroth term
    partial_sum = ith_term;

    for (int i = 1; sx_fabs((double)ith_term) > Sx_EPSILON; ++i) {
      ith_term = -ith_term * x * x / (2 * i + 1) * (2 * (i - 1) + 1);
      partial_sum += ith_term;
    }

  } else {
    ith_term = 1.0 / x;  // 1/x is the zeroth term
    partial_sum = ith_term;

    for (int i = 1; sx_fabs((double)ith_term) > Sx_EPSILON; ++i) {
      ith_term = -ith_term * 1.0 / (x * x * (2 * i + 1)) * (2 * (i - 1) + 1);
      partial_sum += ith_term;
    }
    partial_sum = Sx_PI * sx_fabs(x) / (2 * x) - partial_sum;
  }

  return partial_sum;
}
