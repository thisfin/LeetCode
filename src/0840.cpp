//
// Created by 李毅 on 2021/3/30.
//

#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>> &matrix, int target) {
        // 二分第一列
        vector<vector<int>>::iterator iter = upper_bound(matrix.begin(), matrix.end(), target,
                                                         [](int tgt, vector<int> matrixValue) -> bool {
                                                             return tgt < matrixValue[0];
                                                         });
        if (iter == matrix.begin()) {
            return false;
        }
        iter--;
        // 二分行
        return binary_search(iter->begin(), iter->end(), target);
    }
};
