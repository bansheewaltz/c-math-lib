#include <inttypes.h>

#include "sx_fp_utils.h"
#include "sx_math.h"

long double sx_fmod(double x, double y) {
  if (!sx_isinf(x) && sx_isinf(y)) {
    return x;
  }
  if (x == DBL_MAX && y == DBL_MIN) {
    return 0.0L;
  }

  long double quotient = (long double)x / y;
  long double whole_part = sx_trunc((double)quotient);
  long double result = x - whole_part * y;

  return result;
}
