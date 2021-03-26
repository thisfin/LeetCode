//
// Created by 李毅 on 2021/3/23.
//

#include <cstdint>
#include <limits>

using namespace std;

class Solution {
public:
    int reverse(int x) {
        int source = x;
        __int64_t result = 0;
        for (; source != 0; ) {
            int temp = source % 10;
            source = source / 10;
            result = result * 10 + temp;
            if (result > numeric_limits<__int32_t>::max() || result < numeric_limits<__int32_t>::min()) {
                return 0;
            }
        }
        return result;
    }
};
