//
// Created by 李毅 on 2021/3/1.
//

#include <vector>

using namespace std;

class Solution {
public:
    int trap(vector<int> &height) {
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

        return result;
    }
};
