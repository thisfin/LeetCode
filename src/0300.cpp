//
// Created by 李毅 on 2021/3/11.
//

#include <vector>

using namespace std;

class Solution {
public:
    int lengthOfLIS(vector<int> &nums) {
        vector<int> result = {nums[0]};
        for (vector<int>::iterator iter = nums.begin() + 1; iter < nums.end(); ++iter) {
            if (*iter > result.back()) {
                result.push_back(*iter);
            } else {
                result[lower_bound(result.begin(), result.end(), *iter) - result.begin()] = *iter;
            }
        }
        return result.size();
    }
};
