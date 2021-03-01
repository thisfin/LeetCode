//
// Created by 李毅 on 2021/3/1.
//

#include <vector>

using namespace std;

class NumArray {
public:
    NumArray(vector<int> &nums) {
        int total = 0;
        for (int value : nums) {
            total += value;
            result.push_back(total);
        }
    }

    int sumRange(int i, int j) {
        return result[j] - (i - 1 >= 0 ? result[i - 1] : 0);
    }

private:
    vector<int> result;
};
