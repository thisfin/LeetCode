//
// Created by 李毅 on 2021/3/1.
//

#include <vector>

using namespace std;

class Solution {
public:
    int largestRectangleArea(vector<int> &heights) {
        return 0;
    }
    int largestRectangleAreaOld(vector<int> &heights) { // 遍历过多, 慢
        int result = 0;
        for (int i = 0; i < heights.size(); ++i) {
            int num = 1;
            int height = heights[i];
            for (int x = i - 1; x >= 0; --x) {
                if (heights[x] >= height) {
                    ++num;
                } else {
                    break;
                }
            }
            for (int y = i + 1; y < heights.size(); ++y) {
                if (heights[y] >= height) {
                    ++num;
                } else {
                    break;
                }
            }
            int v = num * height;
            if (v > result) {
                result = v;
            }
        }
        return result;
    }
};
