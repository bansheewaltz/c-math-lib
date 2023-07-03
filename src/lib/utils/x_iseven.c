#include <stdbool.h>

#include "sx_fp_utils.h"
#include "sx_math.h"

bool sx_iseven(double x) {
  if (sx_isint(x) &&
      sx_fabs((double)sx_fmod(x, 2.0)) < Sx_EPSILON) {  // NOLINT
    return true;
  }
  return false;
}
