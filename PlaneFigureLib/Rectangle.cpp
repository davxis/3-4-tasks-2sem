#include "Rectangle.h"
#include "Angle.h"
#include "helpers.h"

Rectangle::Rectangle(const Point maxScreenResolution) : Rectangle(maxScreenResolution,
    Point(0, 2), Point(0, 5), Point(2, 5)) {
}

/*
 * @brief Конструктор для создания прямоугольника с заданными вершинами. 
 * @param maxScreenResolution Максимальное разрешение экрана для проверки допустимых координат.
 * @param a Первая вершина прямоугольника.
 * @param b Вторая вершина прямоугольника.
 * @param c Третья вершина прямоугольника.
 */
Rectangle::Rectangle(const Point maxScreenResolution, const Point a,
    const Point b, const Point c) : maxScreenResolution(maxScreenResolution),
    a(a), b(b), c(c), d(Point(0,0)) {

    validateForMaxScreenResolution(maxScreenResolution);
    validateForEqualPoints(a, b, c);
    setABCChooseBAsRightAngle();
    setD();
}

/*
 * @brief Конструктор для создания прямоугольника с заданными координатами вершин. 
 * @param maxScreenResolution Максимальное разрешение экрана для проверки допустимых координат.
 * @param ax Координата X первой вершины.
 * @param ay Координата Y первой вершины.
 * @param bx Координата X второй вершины.
 * @param by Координата Y второй вершины.
 * @param cx Координата X третьей вершины.
 * @param cy Координата Y третьей вершины.
 */
Rectangle::Rectangle(const Point maxScreenResolution,
    const double ax, const double ay,
    const double bx, const double by,
    const double cx, const double cy) : Rectangle(maxScreenResolution, Point(ax, ay), Point(bx, by), Point(cx, cy)) {
    /* Ничего */
}

/*
 * @brief Проверяет, является ли угол ABC прямым. 
 * Угол считается прямым, если скалярное произведение векторов BA и BC близко к нулю.
 * @param a Первая точка.
 * @param b Вторая точка (вершина угла).
 * @param c Третья точка.
 * @return true Если угол ABC прямой.
 * @return false Если угол ABC не прямой.
 */
bool isRightAngle(Point a, Point b, Point c) {
    double ax = a.getX(), ay = a.getY(),
        bx = b.getX(), by = b.getY(),
        cx = c.getX(), cy = c.getY();
    double bax = ax - bx;
    double bay = ay - by;
    double bcx = cx - bx;
    double bcy = cy - by;
    double scalarProduct = bax * bcx + bay * bcy;
    return doublesEquals(scalarProduct, 0.0);
}

void Rectangle::validateForMaxScreenResolution(const Point maxScreenResolution) {
    if (a.exceedsLimits(maxScreenResolution) ||
        b.exceedsLimits(maxScreenResolution) ||
        c.exceedsLimits(maxScreenResolution)) {
        throw "1 из координат одной из вершин преодолела максимальное значение";
    }
}

/*
 * @brief Проверяет корректность координат вершин прямоугольника.
 * Проверяет, что ни одна из координат не превышает максимальные значения,
 * что все три точки различны и что они образуют прямоугольный треугольник.
 * @param maxScreenResolution Максимальное разрешение экрана для проверки допустимых координат.
 * @throws const char* Если координаты выходят за пределы или точки не образуют прямоугольник.
 */
void Rectangle::validate(Point maxScreenResolution) {
    
    if (a == b || b == c || a == c) {
        throw "2 точки прямоугольника не могут быть идентичными";
    }
    bool aIsRight = isRightAngle(b, a, c);
    bool bIsRight = isRightAngle(a, b, c);
    bool cIsRight = isRightAngle(a, c, b);
    if (!aIsRight && !bIsRight && !cIsRight) {
        throw "3 вершины прямоугольника должны образовывать прямоугольный треугольник";
    }
    if (aIsRight) {
        this->a = b;
        this->b = a;
        this->c = c;
    } else if (bIsRight) {
        this->a = a;
        this->b = b;
        this->c = c;
    } else {
        this->a = a;
        this->b = c;
        this->c = b;
    }
}

/*
 * @brief Возвращает строковое представление прямоугольника. 
 * Переопределяет метод ToString из базового класса Figure2D.
 * @return Строковое представление прямоугольника.
 */
std::string Rectangle::ToString() const {
    return "Rectangle(a = " + a.ToString() + ", b = " +
        b.ToString() + ", c = " + c.ToString() + ", d = " +
        d.ToString() + ")";
}

/*
 * @brief Перегрузка оператора ввода для прямоугольника. 
 * Считывает данные о вершинах прямоугольника из потока ввода.
 * @param is Поток ввода, из которого будут считаны данные о прямоугольнике.
 * @param rect Прямоугольник, в который будут записаны считанные значения.
 * @return Ссылку на поток ввода для поддержки цепочки операций.
 */
std::istream& operator>>(std::istream& is, Rectangle& rect) {
    is >> rect.a >> rect.b >> rect.c;
    rect.validateForMaxScreenResolution(rect.maxScreenResolution);
    rect.validateForEqualPoints(rect.a, rect.b, rect.c);
    rect.setABCChooseBAsRightAngle();
    rect.setD();
    return is;
}


/**
 * @brief Проверяет, что никакие из 3х точек не находятся в одном и том же месте.
 * 
 * @param a Первая точка.
 * @param b Вторая точка.
 * @param c Третья точка.
 * 
 * @throws const char* Исключение, если точки совпадают.
 */
void Rectangle::validateForEqualPoints(const Point& a, const Point& b, const Point& c) {
    // Проверка, что точки не совпадают
    if (a == b) {
        throw "Точка A не должна быть такой же как и точка B";
    }
    if (a == c) {
        throw "Точка A не должна быть такой же как и точка C";
    }
    if (b == c) {
        throw "Точка B не должна быть такой же как и точка C";
    }
}

/**
 * @brief Задаёт значения полей a, b, c на основе значений параметров
 * так, что поле b будет ссылаться на точку с прямым углом.
 *
 * @throws const char* Исключение, если ни один из углов не является прямым.
 */
void Rectangle::setABCChooseBAsRightAngle() {
    Point a = this->a;
    Point b = this->b;
    Point c = this->c;
    // Вычисление углов: являются ли прямые.
    //
    // ВАЖНО! Если ни один из углов не прямой,
    // то это означает, что нельзя построить прямоугольник по
    // заданным точкам.
    Angle angleA(b, a, c), angleB(a, b, c), angleC(a, c, b);
    bool aIsRight = angleA.isRight();
    bool bIsRight = angleB.isRight();
    bool cIsRight = angleC.isRight();

    // Проверка, что хотя бы 1 из углов прямой
    if (!aIsRight && !bIsRight && !cIsRight) {
        throw "3 точки должны образовывать прямоугольный треугольник, чтобы быть вершинами прямоугольника";
    }

    if (aIsRight) {
        this->a = b;
        this->b = a;
        this->c = c;
    } else if (bIsRight) {
        this->a = a;
        this->b = b;
        this->c = c;
    } else {
        this->a = a;
        this->b = c;
        this->c = b;
    }
}

/**
 * @brief Задаёт значение поля d на основе значений полей a, b, c.
 */
void Rectangle::setD() {
    double ax = a.getX(), ay = a.getY(), bx = b.getX(), by = b.getY(),
           cx = c.getX(), cy = c.getY();
    double dx = ax + cx - bx;
    double dy = ay + cy - by;
    this->d = Point(dx, dy);
}

