//
// Created by 李毅 on 2021/3/16.
//

#include <queue>
#include <stack>
#include <vector>

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
    vector<vector<int>> zigzagLevelOrder(TreeNode *root) {
        stack<TreeNode *> nodeStack0;
        stack<TreeNode *> nodeStack1;
        vector<vector<int>> result = vector<vector<int>>();
        if (root != nullptr) {
            nodeStack0.push(root);
        }

        for (; !nodeStack0.empty() || !nodeStack1.empty();) {
            vector<int> line;
            if (!nodeStack0.empty()) {
                for (; !nodeStack0.empty();) {
                    TreeNode *node = nodeStack0.top();
                    nodeStack0.pop();
                    line.push_back(node->val);
                    if (node->left != nullptr) {
                        nodeStack1.push(node->left);
                    }
                    if (node->right != nullptr) {
                        nodeStack1.push(node->right);
                    }
                }
            } else {
                for (; !nodeStack1.empty();) {
                    TreeNode *node = nodeStack1.top();
                    nodeStack1.pop();
                    line.push_back(node->val);
                    if (node->right != nullptr) {
                        nodeStack0.push(node->right);
                    }
                    if (node->left != nullptr) {
                        nodeStack0.push(node->left);
                    }
                }
            }
            result.push_back(line);
        }
        return result;
    }
};