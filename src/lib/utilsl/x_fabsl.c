#include "sx_fp_utilsl.h"
#include "sx_math.h"

long double sx_fabsl(long double x) {
  if (sx_isnanl(x)) {
    return Sx_FP_NAN;
  }

  if (x < 0.0L) {
    return -x;
  }
  return x;
}
