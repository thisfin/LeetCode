//
// Created by 李毅 on 2021/3/5.
//

#include <stack>

using namespace std;

class MyQueue {
public:
    stack<int> header;
    stack<int> footer;

    /** Initialize your data structure here. */
    MyQueue() {
    }

    /** Push element x to the back of queue. */
    void push(int x) {
        while (!footer.empty()) {
            header.push(footer.top());
            footer.pop();
        }
        header.push(x);
    }

    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        int result = peek();
        footer.pop();
        return result;

    }

    /** Get the front element. */
    int peek() {
        while (!header.empty()) {
            footer.push(header.top());
            header.pop();
        }
        return footer.top();
    }

    bool empty() {
        return header.empty() && footer.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */