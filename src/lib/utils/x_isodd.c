#include <stdbool.h>

#include "sx_fp_utils.h"
#include "sx_math.h"

bool sx_isodd(double x) {
  if (sx_isint(x) && !sx_iseven(x)) {  // NOLINT
    return true;
  }
  return false;
}
