#include "Angle.h"

#include <cmath>
#include <climits>

#include "helpers.h"

/*
 * @brief Конструктор, инициализирующий угол заданными тремя точками.
 * @param a Первая точка (A) угла.
 * @param b Вторая точка (B) угла (вершина).
 * @param c Третья точка (C) угла.
 */
Angle::Angle(const Point& a, const Point& b, const Point& c) : a(a), b(b), c(c) {}

/*
 * @brief Проверяет, является ли угол ABC прямым.
 * @return true, если угол ABC - прямой; false в противном случае.
 *
 * Угол считается прямым, если скалярное произведение векторов BA и BC равно нулю.
 * Для проверки используется небольшой порог (epsilon) для учета возможных ошибок округления.
 */
bool Angle::isRight() const {
    Point ba(a.getX() - b.getX(), a.getY() - b.getY());
    Point bc(c.getX() - b.getX(), c.getY() - b.getY());
    double scalarProduct = ba.getX() * bc.getX() + ba.getY() * bc.getY();
    return doublesEquals(scalarProduct, 0);
}
