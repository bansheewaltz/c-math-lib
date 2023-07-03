#include "sx_fp_utils.h"
#include "sx_math.h"

long double sx_fabs(double x) {
  if (sx_isnan(x)) {
    return Sx_FP_NAN;
  }

  if (x < 0.0) {
    return -x;
  }
  return x;
}
