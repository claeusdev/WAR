#include "utils.h"
#include <cstdlib>

unsigned int RandomInteger::operator()(unsigned int max) {
  unsigned int random_val = rand();
  return random_val % max;
};
