//
// Created by 李毅 on 2021/3/2.
//

#include "string"

using namespace std;

class Node {
public:
    Node *pre;
    int value;
    int min;
};

class MinStack {
public:
    MinStack() {
        node = nullptr;
    }

    void push(int x) {
        Node *n = new Node();
        n->value = x;
        if (this->node) {
            n->min = min(x, node->min);
        } else {
            n->min = x;
        }
        n->pre = node;
        node = n;
    }

    void pop() {
        node = node->pre;
    }

    int top() {
        return node->value;
    }

    int getMin() {
        return node->min;
    }

private:
    Node *node;
};
