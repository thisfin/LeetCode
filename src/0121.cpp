//
// Created by 李毅 on 2021/3/11.
//

#include <vector>
#include <limits>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int result = 0;
        int minValue = numeric_limits<int>::max();
        for (int i : prices) {
            minValue = min(minValue, i);
            result = max(result, i - minValue);
        }
        return result;
    }
};
