#include <iostream>
#include <clocale>
#include <vector>

#include "Queue.h"

using namespace std;

/**
 * @brief ����� ����� � ���������.
 *
 * @return ��� ����������.
 */
int main() {
    setlocale(LC_ALL, "rus");
    
    Queue q;
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);

    cout << "Queue: " << q << endl;

    // ����������� �����������
    Queue q2 = q;
    q2.dequeue();

    cout << "Copied and modified queue: " << q2 << endl;
    cout << "Original queue: " << q << endl;

    // ���������� ��� ����������
    return 0;
}
