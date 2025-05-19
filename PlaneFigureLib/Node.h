#pragma once

struct Node {
    int data;
    Node* next;
    Node(const int val) : data(val), next(nullptr) {}
};

