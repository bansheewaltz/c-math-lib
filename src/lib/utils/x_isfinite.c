#include <stdbool.h>

#include "sx_fp_utils.h"

bool sx_isfinite(double x) {
  if (sx_isinf(x) || sx_isnan(x)) {
    return false;
  }
  return true;
}
