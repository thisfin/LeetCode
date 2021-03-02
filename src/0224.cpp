//
// Created by 李毅 on 2021/3/2.
//

#include <string>
#include <vector>
#include <stack>

using namespace std;

class Solution {
public:
    int calculate(string s) {
        stack<string> st;
        for (string::iterator iter = s.begin(); iter != s.end(); ++iter) {
            string c = string({*iter});
            if (c == "(") {
                st.push(c);
            } else if (c == ")") {
                string value = st.top();
                st.pop();
                st.pop(); // 左括号
                if (!st.empty() && (st.top() == "+" || st.top() == "-")) {
                    if (st.top() == "+") {
                        st.pop();
                        int left = stoi(st.top());
                        st.pop();
                        int right = stoi(value);
                        st.push(to_string(left + right));
                    } else {
                        st.pop();
                        int left = 0;
                        if (!st.empty()) {
                            left = stoi(st.top());
                            st.pop();
                        }
                        int right = stoi(value);
                        st.push(to_string(left - right));
                    }
                } else {
                    st.push(value);
                }
            } else if (c == "+") {
                st.push(c);
            } else if (c == "-") {
                st.push(c);
            } else if (c == " ") {
                continue;
            } else {
                if (!st.empty() && (st.top() == "+" || st.top() == "-")) {
                    if (st.top() == "+") {
                        st.pop();
                        int left = stoi(st.top());
                        st.pop();
                        int right = stoi(c);
                        st.push(to_string(left + right));
                    } else {
                        st.pop();
                        int left = 0;
                        if (!st.empty()) {
                            left = stoi(st.top());
                            st.pop();
                        }
                        int right = stoi(c);
                        st.push(to_string(left - right));
                    }
                } else if (!st.empty() && st.top() != "+" && st.top() != "-" && st.top() != "(") {
                    string ne = st.top() + c;
                    st.pop();
                    st.push(ne);
                } else {
                    st.push(c);
                }
            }
        }
        return stoi(st.top());
    }
};
