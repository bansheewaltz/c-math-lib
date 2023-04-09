#ifndef TESTING_H_
#define TESTING_H_

#include <limits.h>
#include <math.h>
#include <stdint.h>
#include <stdlib.h>

#include "s21_math.h"

long double func_Uniform(float left, float right, int i) {
  srand(i % 13);
  long double randomNumber = sin(rand() * rand());
  return left + (right - left) * fabs(randomNumber);
}

#endif  // TESTING_H_