#include "sx_fp_utils.h"
#include "sx_fp_utilsl.h"
#include "sx_math.h"

long double sx_sqrt(double x) {
  if (x < 0.0) {
    return Sx_FP_NAN;
  }
  if (x == 0.0) {
    return 0.0;
  }
  if (sx_ispinf(x)) {
    return Sx_FP_PINF;
  }

  long double intermediate_value = x;
  long double prev_value = 1;

  if (x > 0) {
    while (sx_fabsl(intermediate_value - prev_value) > Sx_EPSILON) {
      intermediate_value = prev_value;
      prev_value = (prev_value + (x / prev_value)) / 2;
    }
  }

  return intermediate_value;
}
