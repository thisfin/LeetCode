//
// Created by 李毅 on 2021/3/1.
//

#include <vector>

using namespace std;

class Solution {
public:
    int trap(vector<int> &height) {
        int lMax = 0;
        int rMax = 0;
        int result = 0;

        // 动态找最高点, 两端指针遍历
        for (int left = 0, right = height.size() - 1; left < right;) {
            int hr = height[right];
            int hl = height[left];
            if (hr > hl) {
                if (hl <= lMax) {
                    result += (lMax - hl);
                } else {
                    lMax = hl;
                }
                left++;
            } else {
                if (hr <= rMax) {
                    result += (rMax - hr);
                } else {
                    rMax = hr;
                }
                right--;
            }
        }
        return result;
    }

    int trapOld(vector<int> &height) {
        int lastMaxIndex = 0;
        int maxValue = 0;
        int result = 0;
        int tmpResult = 0;

        // 正向遍历, 得出最后一个最高点的位置及之前的结果
        for (int i = 0; i < height.size(); ++i) {
            int v = height[i];
            if (v >= maxValue) {
                result += tmpResult;
                tmpResult = 0;

                maxValue = v;
                lastMaxIndex = i;
            } else {
                tmpResult += (maxValue - v);
            }
        }

        // 反向遍历到最后一个最高点, 与之前的结果相加
        tmpResult = 0;
        maxValue = 0;
        if (height.size() > 0) {
            for (int i = height.size() - 1; i >= lastMaxIndex; --i) {
                int v = height[i];
                if (v >= maxValue) {
                    result += tmpResult;
                    tmpResult = 0;

                    maxValue = v;
                } else {
                    tmpResult += (maxValue - v);
                }
            }
        }

        // 可以优化为左右两边一同遍历, 找最高点, 单次循环, 双指针
        return result;
    }
};
