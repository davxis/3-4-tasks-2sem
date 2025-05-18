#include "helpers.h"

#include <cmath>
#include <limits>

// doublesEquals возвращает true, если a равно b.
bool doublesEquals(double a, double b) {
    return std::fabs(a - b) < std::numeric_limits<double>::epsilon();
}
