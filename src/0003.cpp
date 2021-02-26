//
// Created by 李毅 on 2021/2/25.
//

#include <set>
#include <string>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<char> vec;
        int max = 0;
        for (string::iterator iterator = s.begin(); iterator != s.end(); ++iterator) {
            char c = *iterator;
            vector<char>::iterator index = find(vec.begin(), vec.end(), c);
            if (index != vec.end()) {
                vec.erase(vec.begin(), index + 1);
            }
            vec.push_back(*iterator);
            if (vec.size() > max) {
                ++max;
            }
        }
        return max;
    }
};
