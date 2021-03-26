//
// Created by 李毅 on 2021/3/23.
//

#include <string>
#include <limits>
#include <vector>

using namespace std;

class Solution {
public:
    int myAtoi(string s) {
        // 状态机
        /*
        START:  {START, SIGN, NUMBER, END},
        SIGN:   {END,   END,  NUMBER, END},
        NUMBER: {END,   END,  NUMBER, END},
        END:    {END,   END,  END,    END}
         */
        vector<vector<status>> vv = {
                {START, SIGN, NUMBER, END},
                {END,   END,  NUMBER, END},
                {END,   END,  NUMBER, END},
                {END,   END,  END,    END}};
        status sta = START;
        int sign = 1;
        __int64_t result = 0;

        for (char c: s) {
            sta = vv[sta][getIndex(c)];
            switch (sta) {
                case START:
                    break;
                case SIGN:
                    sign = (c == '-' ? -1 : 1);
                    break;
                case NUMBER:
                    result = result * 10 + (c - '0');
                    if (result * sign > numeric_limits<__int32_t>::max()) {
                        return numeric_limits<__int32_t>::max();
                    } else if (result * sign < numeric_limits<__int32_t>::min()) {
                        return numeric_limits<__int32_t>::min();
                    }
                    break;
                case END:
                    return result * sign;
            }
        }
        return result * sign;
    }

private:
    enum status {
        START = 0, SIGN, NUMBER, END
    };

    status getIndex(char c) {
        if (isdigit(c)) {
            return NUMBER;
        } else if (isspace(c)) {
            return START;
        } else if (c == '+' || c == '-') {
            return SIGN;
        }
        return END;
    }
};
