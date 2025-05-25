#include "Queue.h"

#include <sstream>

using namespace std;

Queue::Queue() : front(nullptr), rear(nullptr) {
    // nothing    
}

Queue::Queue(const Queue& other) : front(nullptr), rear(nullptr) {
    // «десь был следующий код:
    //  Node* cur = other.front;
    //  while (cur) {
    //    enqueue(cur->data);
    //    cur = cur->next;
    //  }

    // Ќа ревью было запрошено:
    // "ѕросто переопределить хвост и голову".

    // ≈сли имелось в виду сделать так:
    //  this->front = front;
    //  this->rear = rear;
    // то это не верно, т.к. в этом случае и other и this
    // будут иметь доступ к одним и тем же узлам очереди,
    // а конструктор копировани€ (не перемещени€) предполагает
    // создание полноценного клона.
    //
    // ≈сли просто скопировать адреса, то после вызова деструктора дл€
    // this, как только вызоветс€ деструктор дл€ other случитс€ ошибка,
    // т.к. данные на куче уже были освобождены.
    
    // ≈сли согласно ревью под словами "ѕросто переопределить хвост и голову"
    // имелось в виду "Ќе использовать готовые методы класса Queue
    // наподобие enqueue(), то вот исправленный вариант:

    Node* otherCurrent = other.front;
    Node* theRear = nullptr;
    front = nullptr;
    while (otherCurrent) {
        Node* node = new Node(otherCurrent->data);
        if (!front) {
            front = node;
        }
        if (theRear) {
            theRear->next = node;
        }
        theRear = node;
        otherCurrent = otherCurrent->next;
    }
    rear = theRear;
}

Queue::Queue(Queue&& other) noexcept : front(other.front), rear(other.rear) {
    other.front = nullptr;
    other.rear = nullptr;
}

Queue::~Queue() {
    clear();
}

void Queue::enqueue(const int value) {
    Node* node = new Node(value);
    if (rear) {
        rear->next = node;
    } else {
        front = node;
    }
    rear = node;
}

int Queue::dequeue() {
    if (isEmpty()) {
        throw "Queue is empty";
    }
    Node* tmp = front;
    int val = tmp->data;
    front = front->next;
    if (!front) {
        rear = nullptr;
    }
    delete tmp;
    return val;
}

bool Queue::isEmpty() const {
    return front == nullptr;
}


int Queue::peek() const {
    if (isEmpty()) {
        throw "Queue is empty";
    }
    return front->data;
}

void Queue::clear() {
    while (!isEmpty()) {
        dequeue();
    }
}

size_t Queue::size() const {
    size_t cnt = 0;
    Node* cur = front;
    while (cur) {
        cnt++;
        cur = cur->next;
    }
    return cnt;
}

Queue& Queue::operator=(const Queue& other) {
    if (this == &other) {
        return *this;
    }
    clear();
    Node* cur = other.front;
    while (cur) {
        enqueue(cur->data);
        cur = cur->next;
    }
    return *this;
}

string Queue::toString() const {
    ostringstream s;
    Node* cur = front;
    while (cur) {
        s << cur->data;
        if (cur->next) {
            s << " ";
        }
        cur = cur->next;
    }
    return s.str();
}

std::ostream& operator<<(ostream& os, const Queue& q) {
    return os << q.toString();
}

std::istream& operator>>(istream& is, Queue& q) {
    int val = 0;
    while (is >> val) {
        q.enqueue(val);
    }
    return is;
}
