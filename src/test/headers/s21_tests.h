#ifndef TESTING_H_
#define TESTING_H_

#include <limits.h>
#include <math.h>
#include <stdint.h>
#include <stdlib.h>

#include "s21_math.h"

#ifndef M_PI
#define M_PI 3.14159265358979323846264338327950288
#endif

#define S21_TOLERANCE 1e-6
#define MAGIC 13

long double func_Uniform(double left, double right, int i) {
  srand((unsigned int)(i % MAGIC));
  long double randomNumber = sin((double)rand() * rand());  // NOLINT
  return left + (right - left) * fabs((double)randomNumber);
}

#endif  // TESTING_H_
