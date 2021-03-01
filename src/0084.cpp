//
// Created by 李毅 on 2021/3/1.
//

#include <stack>
#include <vector>

using namespace std;

class Solution {
public:
    int largestRectangleArea(vector<int> &heights) {
        int n = heights.size();
        vector<int> lefts(n, -1); // 左减位
        vector<int> rights(n, n); // 右减位
        stack<int> lowStack;
        for (int i = 0; i < n; ++i) {
            for (; !lowStack.empty() && heights[lowStack.top()] >= heights[i];) {
                rights[lowStack.top()] = i;
                lowStack.pop();
            }

            lefts[i] = lowStack.empty() ? -1 : lowStack.top();
            lowStack.push(i);
        }

        int result = 0;
        for (int i = 0; i < n; ++i) {
            result = max(result, heights[i] * (rights[i] - lefts[i] - 1));
        }
        return result;
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
