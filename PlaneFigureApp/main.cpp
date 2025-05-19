#include <iostream>
#include <clocale>
#include <vector>

#include "Queue.h"

using namespace std;

/**
 * @brief Точка входа в программу.
 *
 * @return Код завершения.
 */
int main() {
    setlocale(LC_ALL, "rus");
    
    Queue q;
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);

    cout << "Queue: " << q << endl;

    // Конструктор копирования
    Queue q2 = q;
    q2.dequeue();

    cout << "Copied and modified queue: " << q2 << endl;
    cout << "Original queue: " << q << endl;

    // Возвращаем код завершения
    return 0;
}
