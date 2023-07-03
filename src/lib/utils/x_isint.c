#include <stdbool.h>
#include <stdint.h>

#include "sx_fp_utils.h"

bool sx_isint(double x) {
  if (sx_isfinite(x) && sx_trunc(x) == (long double)x) {
    return true;
  }
  return false;
}
