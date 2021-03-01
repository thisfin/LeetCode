//
// Created by 李毅 on 2021/2/26.
//

#include <string>

using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        // 补位, 为了基数和偶数适用一套逻辑
        string source = "#";
        for (char c : s) {
            source.push_back(c);
            source.push_back('#');
        }

        int index = 0;
        int max = 0;
        for (int i = 0; i < source.size(); ++i) {
            int si = 0;
            for (int step = 1;; ++step) { // 步进对比
                if ((i - step) >= 0 && (i + step) < source.size() && source[i - step] == source[i + step]) {
                    si = step;
                } else {
                    break;
                }
            }
            if (si > max) {
                max = si;
                index = i;
            }
        }

        // 拼接结果
        string result = "";
        for (int i = index - max; i <= index + max; ++i) {
            if (source[i] != '#') {
                result.push_back(source[i]);
            }
        }
        return result;
    }
};
