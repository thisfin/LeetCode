#include <iostream>
#include <vector>
#include "src/0300.cpp"

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

vector<int>a({10,9,2,5,3,7,101,18});
    cout << Solution().lengthOfLIS(a) << endl;
//    cout << Solution().countBits(2) << endl;
    return 0;
}
