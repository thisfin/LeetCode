#include <iostream>
#include <vector>
#include "src/0123.cpp"

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
//    TreeNode * node = new TreeNode(-3);

vector<int>a({3,3,5,0,0,3,1,4});
a = {2,4,1};
    cout << Solution().maxProfit(a) << endl;
//    cout << Solution().countBits(2) << endl;
    return 0;
}
