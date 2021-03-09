//
// Created by 李毅 on 2021/3/9.
//

#include <string>

using namespace std;

class Solution {
public:
    string removeDuplicates(string S) {
        string result;
        for (char c: S) {
            if (!result.empty() && result.back() == c) {
                result.pop_back();
            } else {
                result.push_back(c);
            }
        }
        return result;
    }
};
