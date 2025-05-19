#pragma once

#include <string>

// doublesEquals возвращает true, если a равно b.
bool doublesEquals(double a, double b);

// doubleToString преобразует значение типа double
// в строку таким образом, что незначащие нули не отображаются,
// как, например, при использовании to_string(double_value).
std::string doubleToString(double value);
