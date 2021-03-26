//
// Created by 李毅 on 2021/3/27.
//

#include <string>

using namespace std;

class Solution {
public:
    string removeOuterParentheses(string S) {
        int leftCount = 0;
        string result;
        for (char c : S) {
            if (c == '(') {
                if (leftCount++ > 0) {
                    result.push_back(c);
                }
            } else if (c == ')') {
                if (--leftCount > 0) {
                    result.push_back(c);
                }
            }
        }
        return result;
    }
};
