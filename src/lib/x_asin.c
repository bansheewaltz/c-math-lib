#include "sx_fp_utils.h"
#include "sx_math.h"

// through atan
long double sx_asin(double x) {
  const double SYSTEMLIB_SIN_PI_4 = 0.70710678118654746;

  if (x < -1.0 || 1.0 < x) {
    return +Sx_FP_NAN;
  }
  if (x == +1.0) {
    return +Sx_PI_2;
  }
  if (x == -1.0) {
    return -Sx_PI_2;
  }
  if (x == +SYSTEMLIB_SIN_PI_4) {
    return +Sx_PI_4;
  }
  if (x == -SYSTEMLIB_SIN_PI_4) {
    return -Sx_PI_4;
  }

  return sx_atan((double)((long double)x / sx_sqrt(1 - x * x)));
}
