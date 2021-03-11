//
// Created by 李毅 on 2021/3/11.
//

#include <vector>
#include <limits>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minValue = numeric_limits<int>::max();
        int diff = 0;
        int minIndex = 0;
        int maxIndex = 0;
        int minIndexTrue = 0;
        for (int index = 0; index < prices.size(); ++index) {
            int i = prices[index];
            if (minValue > i) {
                minValue = i;
                minIndex = index;
            }
            if (diff < i - minValue) {
                diff = i - minValue;
                maxIndex = index;
                minIndexTrue = minIndex;
            }
        }

        int mid = diff;
        int left = maxProfit(prices, 0, minIndexTrue);
        int right = maxProfit(prices, maxIndex + 1, prices.size());
        int mid2 = minProfit(prices, minIndexTrue + 1, maxIndex);

        int lr = max(left, right);
        if (lr > mid2) {
            return mid + lr;
        } else {
            return mid + mid2;
        }
    }

    int maxProfit(vector<int>& prices, int begin, int end) {
        if (begin >= end) {
            return 0;
        }
        int result = 0;
        int minValue = numeric_limits<int>::max();
        for (int index = begin; index < end; ++index) {
            int i = prices[index];
            minValue = min(minValue, i);
            result = max(result, i - minValue);
        }
        return result;
    }

    int minProfit(vector<int>& prices, int begin, int end) {
        if (begin >= end) {
            return 0;
        }
        int result = 0;
        int minValue = numeric_limits<int>::max();
        for (int index = end - 1; index >= begin; --index) {
            int i = prices[index];
            minValue = min(minValue, i);
            result = max(result, i - minValue);
        }
        return result;
    }
};
// 参考 121, 求最大正差, 然后 0 -- minIndex, maxIndex -- n 求正差, minIndex + 1 -- maxIndex 求逆差，最大正插 + 其他差的最大值为解
