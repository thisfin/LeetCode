#include <iostream>
#include <vector>
#include "src/0124.cpp"

using namespace std;

int main() {
    vector<vector<char>> v = {
            {'1', '0', '1', '0', '0'},
            {'1', '0', '1', '1', '1'},
            {'1', '1', '1', '1', '1'},
            {'1', '0', '0', '1', '0'}
    };

//    ["MinStack","push","push","push","getMin","pop","top","getMin"]
//    [[],[-2],[0],[-3],[],[],[],[]]
//
//    输出：
//    [null,null,null,null,-3,null,0,-2]
    TreeNode * node = new TreeNode(-3);

    cout << Solution().maxPathSum(node) << endl;
//    cout << Solution().countBits(2) << endl;
    return 0;
}
