//
// Created by 李毅 on 2021/3/1.
//

#include <stack>
#include <string>

using namespace std;

class Solution {
public:
    bool isValid(string s) {
        stack<char> charStack;
        for (char c: s) {
            if (isLeft(c)) {
                charStack.push(c);
            } else {
                if (!charStack.empty() && isMatch(charStack.top(), c)) {
                    charStack.pop();
                } else {
                    return false;
                }
            }
        }
        return charStack.empty();
    }

private:
    bool isLeft(char c) {
        return c == '(' || c == '[' || c == '{';
    }

    bool isMatch(char left, char right) {
        return (left == '(' && right == ')') || (left == '[' && right == ']') || (left == '{' && right == '}');
    }
};
