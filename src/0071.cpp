//
// Created by 李毅 on 2021/3/1.
//

#include <iostream>
#include <regex>
#include <stack>
#include <string>
#include <sstream>

using namespace std;

class Solution {
public:
    string simplifyPath(string path) {
        vector<string> paths; // 使用 getline 比正则快
        stringstream ss(path);
        for (string s; getline(ss, s, '/');) {
            if (s == "." || s == "") {
                continue;
            } else if (s == "..") {
                if (!paths.empty()) {
                    paths.pop_back();
                }
            } else {
                paths.push_back(s);
            }
        }

        string result = "";
        for (string path : paths) {
            result += ("/" + path);
        }
        return result.size() > 0 ? result : "/";
    }

    string simplifyPathOld(string path) {
        regex re("/");
        sregex_token_iterator iter(path.begin(), path.end(), re, -1);
        sregex_token_iterator end;
        vector<string> paths;
        for (; iter != end; ++iter) {
            string s = *iter;
            if (s == ".") {
                continue;
            } else if (s.size() == 0) {
                continue;
            } else if (s == "..") {
                if (!paths.empty()) {
                    paths.pop_back();
                }
            } else {
                paths.push_back(s);
            }
        }

        string result = "";
        for (string path : paths) {
            result += ("/" + path);
        }
        return result.size() > 0 ? result : "/";
    }
};
