//
// Created by 李毅 on 2021/2/25.
//

#include <vector>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int> &nums, int target) {
        vector<int> result;
        for (int x = 0; x < nums.size(); ++x) {
            for (int y = x + 1; y < nums.size(); ++y) {
                if (nums[x] + nums[y] == target) {
                    result.push_back(x);
                    result.push_back(y);
                    goto stop;
                }
            }
        }
        stop:
        return result;
    }
};
