#include "sx_fp_utils.h"
#include "sx_math.h"

// through atan
long double sx_acos(double x) {
  const double SYSTEMLIB_COS_PI_4 = 0.70710678118654752;
  const double SYSTEMLIB_COS_3_PI_4 = -0.70710678118654746;

  if (x < -1.0 || 1.0 < x) {
    return Sx_FP_NAN;
  }
  if (x == +1.0) {
    return 0.0L;
  }
  if (x == -1.0) {
    return Sx_PI;
  }
  if (x == 0.0) {
    return Sx_PI_2;
  }
  if (x == SYSTEMLIB_COS_PI_4) {
    return Sx_PI_4;
  }
  if (x == SYSTEMLIB_COS_3_PI_4) {
    return Sx_PI - Sx_PI_4;
  }

  long double res = sx_atan((double)(sx_sqrt(1 - x * x) / (long double)x));

  if (-1.0 < x && x < 0.0) {
    res = res + Sx_PI;
  }

  return res;
}
