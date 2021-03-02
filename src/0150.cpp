//
// Created by 李毅 on 2021/3/2.
//

#include <stack>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> ss;
        for (string token: tokens) {
            if (token == "+") {
                int b = ss.top();
                ss.pop();
                int a = ss.top();
                ss.pop();
                ss.push(a + b);
            } else if (token == "-") {
                int b = ss.top();
                ss.pop();
                int a = ss.top();
                ss.pop();
                ss.push(a - b);
            } else if(token == "*") {
                int b = ss.top();
                ss.pop();
                int a = ss.top();
                ss.pop();
                ss.push(a * b);
            } else if(token == "/") {
                int b = ss.top();
                ss.pop();
                int a = ss.top();
                ss.pop();
                ss.push(a / b);
            } else {
                ss.push(stoi(token));
            }
        }
        return ss.top();
    }
};
