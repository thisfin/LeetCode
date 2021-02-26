//
// Created by 李毅 on 2021/2/26.
//

#include <string>
#include <iostream>

using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        int max = 1;
        string result = string({s[0]});

        for (int i = 0; i < s.size(); ++i) {
            int num1 = 1;

            string ss = string({s[i]});
            for (int step = 1;; ++step) {
                if ((i - step) >= 0 && (i + step) < s.size()) {
                    if (s[i - step] == s[i + step]) {
                        num1 += 2;
                        ss.insert(ss.begin(), s[i - step]);
                        ss.push_back(s[i + step]);
                        cout << ss << endl;
                    } else {
                        break;
                    }
                } else {
                    break;
                }
            }
            if (max < num1) {
                result = ss;
            }
            max = max > num1 ? max : num1;

            int num2 = 0;
            ss = "";
            for (int step = 1;; ++step) {
                if ((i + 1 - step) >= 0 && (i + step) < s.size()) {
                    if (s[i + 1 - step] == s[i + step]) {
                        num2 += 2;
                        ss.insert(ss.begin(), s[i + 1 - step]);
                        ss.push_back(s[i + step]);
                        cout << ss << endl;
                    } else {
                        break;
                    }
                } else {
                    break;
                }
            }
            if (max < num2) {
                result = ss;
            }
            max = max > num2 ? max : num2;
        }
        cout << max << endl;
        return result;
    }
};
