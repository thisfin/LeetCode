//
// Created by 李毅 on 2021/3/2.
//

#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1) {
            return s;
        }
        vector<string> ss(numRows);
        int width = numRows * 2 - 2;
        for (int i = 0; i < s.size(); ++i) {
            int a = i % width;
            if (a < numRows) {
                ss[a].push_back(s[i]);
            } else {
                ss[width - a].push_back(s[i]);
            }
        }
        string result = "";
        for (string str: ss) {
            result.append(str);
        }
        return result;
    }
};
