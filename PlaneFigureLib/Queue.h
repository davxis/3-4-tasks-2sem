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
    void enqueue(int value);
    int dequeue();
    bool isEmpty();
    int peek();
    void clear();

    Queue& operator=(const Queue& other);

    std::string toString() const;

    friend std::ostream& operator<<(std::ostream& os, const Queue& q);
    friend std::istream& operator>>(std::istream& is, Queue& q);
};


