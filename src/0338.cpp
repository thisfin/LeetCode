//
// Created by 李毅 on 2021/3/3.
//

#include <vector>

using namespace std;

class Solution {
public:
    vector<int> countBits(int num) {
        vector<int> result(num + 1, 0);
        for (int i = 1, x = 1; i <= num; ++i) {
            result[i] = result[i & (i - 1)] + 1;
        }
        return result;
    }

    vector<int> countBitsOld(int num) {
        vector<int> result(num + 1, 0);
        for (int i = 1, x = 1; i <= num; ++i) {
            if ((i & (i - 1)) == 0) {
                x = i;
            }
            result[i] = result[i - x] + 1;
        }
        return result;
    }
};
