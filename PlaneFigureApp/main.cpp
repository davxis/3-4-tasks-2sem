#include <iostream>
#include <clocale>
#include <vector>
#include "Point.h"
#include "Rectangle.h"
#include "Figure2D.h"

using namespace std;

/**
 * @brief Точка входа в программу.
 * Устанавливает русскую локаль, создает объект прямоугольника,
 * позволяет пользователю вводить новые координаты и выводит
 * информацию о прямоугольнике.
 * @return Код завершения.
 */
int main() {
    setlocale(LC_ALL, "rus");
    const Point maxScreenResolution(640, 480); // Максимальное разрешение экрана
    vector<Figure2D*> figures;

    try {
        // Ввод трех точек для прямоугольника
        Point point1, point2, point3;
        
        cout << "Введите координаты первой точки (x y): ";
        cin >> point1;
        
        cout << "Введите координаты второй точки (x y): ";
        cin >> point2;
        
        cout << "Введите координаты третьей точки (x y): ";
        cin >> point3;

        // Создание прямоугольника с проверкой границ экрана
        Rectangle r = Rectangle(maxScreenResolution, point1, point2, point3);

        // Вывод информации о прямоугольнике через перегруженный оператор <<
        cout << "\nСозданный прямоугольник:\n";
        cout << r;  // Используем оператор << вместо метода print()

    } catch (const char* msg) {
        cout << "Ошибка: " << msg << endl;
        return 1;
    } catch (...) {
        cout << "Неизвестная ошибка при создании прямоугольника" << endl;
        return 1;
    }

    return 0;
}
