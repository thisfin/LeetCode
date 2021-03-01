//
// Created by 李毅 on 2021/3/2.
//

#include <vector>

using namespace std;

class NumMatrix {
public:
    NumMatrix(vector<vector<int>> &matrix) {
        sum = matrix;
        for (int x = 0; x < matrix.size(); ++x) {
            int sumRow = 0;
            for (int y = 0; y < matrix[x].size(); ++y) {
                sumRow += matrix[x][y];
                sum[x][y] = sumRow + ((x - 1 >= 0) ? sum[x - 1][y] : 0);
            }
        }
    }

    int sumRegion(int row1, int col1, int row2, int col2) {
        int lowRow = row1 - 1;
        int lowCol = col1 - 1;
        return sum[row2][col2] - (lowRow >= 0 ? sum[lowRow][col2] : 0) - (lowCol >= 0 ? sum[row2][lowCol] : 0) +
               (lowRow >= 0 && lowCol >= 0 ? sum[lowRow][lowCol] : 0);
    }

private:
    vector<vector<int>> sum;
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */
