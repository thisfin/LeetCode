//
// Created by 李毅 on 2021/3/9.
//

#include <string>
#include <limits>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}

    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    int maxPathSum(TreeNode *root) {
        loop(root);
        return total;
    }

private:
    int total = numeric_limits<int>::min();

    int loop(TreeNode *treeNode) {
        int count = treeNode->val;
        int line = 0;
        if (treeNode->left) {
            int left = loop(treeNode->left);
            line = max(line, left);
            count += max(0, left);
        }
        if (treeNode->right) {
            int right = loop(treeNode->right);
            line = max(line, right);
            count += max(0, right);
        }
        total = max(total, count);
        return line + treeNode->val;
    }
};
