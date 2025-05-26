#pragma once

#include <iostream>
#include "Node.h"

class Queue {
private:
    // Вложенная структура Node
    struct Node {
        int data;
        Node* next;
        Node(const int val) : data(val), next(nullptr) {}
    };

    Node* front;
    Node* rear;

public:
    Queue();
    Queue(const Queue& other);
    Queue(Queue&& other) noexcept;
    ~Queue();
    void enqueue(const int value);
    int dequeue();
    bool isEmpty() const;
    int peek() const;
    void clear();
    size_t size() const;

    Queue& operator=(const Queue& other);  // Copy assignment
    Queue& operator=(Queue&& other) noexcept;  // Move assignment (добавлен)

    std::string toString() const;

    friend std::ostream& operator<<(std::ostream& os, const Queue& q);
    friend std::istream& operator>>(std::istream& is, Queue& q);
};
