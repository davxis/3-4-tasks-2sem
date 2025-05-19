#pragma once

#include <iostream>
#include "Node.h"

class Queue {
private:
    Node* front;
    Node* rear;
public:
    Queue();
    Queue(const Queue& other);
    ~Queue();
    void enqueue(const int value);
    int dequeue();
    bool isEmpty() const;
    int peek() const;
    void clear();

    Queue& operator=(const Queue& other);

    std::string toString() const;

    friend std::ostream& operator<<(std::ostream& os, const Queue& q);
    friend std::istream& operator>>(std::istream& is, Queue& q);
};


