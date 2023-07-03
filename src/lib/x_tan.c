#include "sx_fp_utils.h"
#include "sx_math.h"

long double sx_tan(double x) {
  if (sx_isnan(x)) {
    return Sx_FP_NAN;
  }
  if (sx_isinf(x)) {
    return Sx_FP_NAN;
  }

  long double inp = sx_trig_range_reduction((long double)x);

  return sx_sin((double)inp) / sx_cos((double)inp);
}
