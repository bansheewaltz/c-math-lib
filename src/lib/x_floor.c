#include "sx_fp_utils.h"

long double sx_floor(double x) {
  if (!sx_isfinite(x)) {
    return x;
  }
  if (sx_isint(x)) {
    return x;
  }

  long double truncated_value = sx_trunc(x);

  if (x < 0) {
    --truncated_value;
  }

  return truncated_value;
}
