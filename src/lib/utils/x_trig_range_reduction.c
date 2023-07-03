#include "sx_math.h"

long double sx_trig_range_reduction(long double x) {
  if (x < -Sx_PI || Sx_PI < x) {
    return sx_fmod((double)x, (double)(Sx_PI * 2));
  }

  return x;
}
