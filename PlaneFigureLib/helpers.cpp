#include "helpers.h"

#include <cmath>
#include <limits>
#include <sstream>

// doublesEquals возвращает true, если a равно b.
bool doublesEquals(double a, double b) {
    return std::fabs(a - b) < std::numeric_limits<double>::epsilon();
}

// doubleToString преобразует значение типа double
// в строку таким образом, что незначащие нули не отображаются,
// как, например, при использовании to_string(double_value).
std::string doubleToString(double value) {
    std::ostringstream oss;
    // По умолчанию выводит без лишних нулей
    oss << value;
    return oss.str();
}
