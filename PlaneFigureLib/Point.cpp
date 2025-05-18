#include "Point.h"
#include "helpers.h"

using namespace std;

/*
 * @brief Конструктор для создания точки с координатами (0; 0). 
 */
Point::Point() : x(0.0), y(0.0) {}

/*
 * @brief Конструктор для создания точки с заданными координатами. 
 * @param x Координата X точки.
 * @param y Координата Y точки.
 */
Point::Point(const double x, const double y) : x(x), y(y) {}

/*
 * @brief Оператор сравнения на равенство. 
 * Проверяет, равны ли текущая точка и другая точка.
 * @param other Другая точка для сравнения.
 * @return true, если точки равны; false в противном случае.
 */
bool Point::operator==(const Point& other) const {
    return doublesEquals(this->x, other.x)
        && doublesEquals(this->y, other.y);
}

/*
 * @brief Оператор сравнения на неравенство. 
 * Проверяет, не равны ли текущая точка и другая точка.
 * @param other Другая точка для сравнения.
 * @return true, если точки не равны; false в противном случае.
 */
bool Point::operator!=(const Point& other) const {
    return !(*this == other);
}

/*
 * @brief Проверка координат точки на превышение лимитов.
 * Возвращает true, если хотя бы одна из координат текущей точки
 * больше или равна соответствующим координатам другой точки.
 * @param limits Другая точка для сравнения.
 * @return true, если текущая точка больше или равна другой; false в противном случае.
 */
bool Point::exceedsLimits(const Point& limits) {
    return x >= limits.x || y >= limits.y;
}

/*
 * @brief Перегрузка оператора вывода для точки. 
 * Выводит координаты точки в поток вывода.
 * @param os Поток вывода, в который будет записано представление точки.
 * @param p Точка, которую нужно вывести.
 * @return Ссылку на поток вывода для поддержки цепочки операций.
 */
std::ostream& operator<<(std::ostream& os, const Point& p) {
    os << '(' << p.x << "; " << p.y << ')';
    return os;
}

/*
 * @brief Перегрузка оператора ввода для точки. 
 * Считывает координаты точки из потока ввода.
 * @param is Поток ввода, из которого будут считаны координаты.
 * @param p Точка, в которую будут записаны считанные значения.
 * @return Ссылку на поток ввода для поддержки цепочки операций.
 */
std::istream& operator>>(std::istream& is, Point& p) {
    is >> p.x >> p.y;
    return is;
}

/*
 * @brief Преобразует точку в строковое представление. 
 * Возвращает строку, содержащую координаты точки в формате "(x; y)".
 * @return Строковое представление точки.
 */
std::string Point::ToString() const {
    return string("(") + doubleToString(x) + "; " + doubleToString(y) + ")";
}

double Point::getX() const {
    return this->x;
}

double Point::getY() const {
    return this->y;
}