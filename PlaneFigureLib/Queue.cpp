#include "Queue.h"

#include <sstream>

using namespace std;

Queue::Queue() : front(nullptr), rear(nullptr) {
    // nothing    
}

Queue::Queue(const Queue& other) : front(nullptr), rear(nullptr) {
    Node* cur = other.front;
    while (cur) {
        enqueue(cur->data);
        cur = cur->next;
    }
}

Queue::~Queue() {
    clear();
}

void Queue::enqueue(int value) {
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

bool Queue::isEmpty() {
    return front == nullptr;
}


int Queue::peek() {
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
    int val;
    while (is >> val) {
        q.enqueue(val);
    }
    return is;
}
