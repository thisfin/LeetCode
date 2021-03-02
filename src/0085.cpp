//
// Created by 李毅 on 2021/3/2.
//

#include <vector>
#include <stack>

using namespace std;

class Solution {
public:
    int maximalRectangle(vector<vector<char>> &matrix) { // 84 加一层循环
        if (matrix.size() <= 0) {
            return 0;
        }

        vector<vector<int>> sums(matrix.size(), vector<int>(matrix[0].size(), 0));
        for (int col = 0; col < matrix[0].size(); ++col) {
            int total = 0;
            for (int row = matrix.size() - 1; row >= 0; --row) {
                int i = (matrix[row][col] == '1' ? 1 : 0);
                if (i == 0) {
                    total = 0;
                } else {
                    total += i;
                }
                sums[row][col] = total;
            }
        }

        int result = 0;
        for (int row = 0; row < sums.size(); ++row) {
            int n = sums[row].size();
            vector<int> lefts(n, -1); // 左减位
            vector<int> rights(n, n); // 右减位
            stack<int> lowStack;
            for (int col = 0; col < n; ++col) {
                for (; !lowStack.empty() && sums[row][lowStack.top()] >= sums[row][col];) {
                    rights[lowStack.top()] = col;
                    lowStack.pop();
                }

                lefts[col] = lowStack.empty() ? -1 : lowStack.top();
                lowStack.push(col);
            }

            for (int col = 0; col < n; ++col) {
                result = max(result, sums[row][col] * (rights[col] - lefts[col] - 1));
            }
        }
        return result;
    }
};
