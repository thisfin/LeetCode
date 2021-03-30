//
// Created by 李毅 on 2021/3/30.
//

#include <string>

using namespace std;

class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0 || (x != 0 && x % 10 == 0)) {
            return false;
        }
        int i = 0;
        // 反转到中间位
        while (i < x) {
            i = i * 10 + x % 10;
            x = x / 10;
        }
        // 偶数位或者奇数位的两种判断
        return i == x || i / 10 == x;
    }
};
