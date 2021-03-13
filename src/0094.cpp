//
// Created by 李毅 on 2021/3/12.
//

#include <vector>
#include <stack>

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
    vector<int> inorderTraversal(TreeNode *root) { // morris 遍历法
        TreeNode *node = root;
        vector<int> result;
        for (; node != nullptr;) {
            if (node->left != nullptr) {
                TreeNode *temp = node->left;
                for (;;) {
                    if (temp->right != nullptr) {
                        temp = temp->right;
                    } else {
                        temp->right = node;
                        break;
                    }
                }
                temp = node->left;
                node->left = nullptr;
                node = temp;
            } else {
                result.push_back(node->val);
                node = node->right;
            }
        }
        return result;
    }

    vector<int> inorderTraversalOld(TreeNode *root) {
        TreeNode *node = root;
        vector<int> result;
        stack<TreeNode *> temp;

        for (; node != nullptr;) {
            TreeNode *left = node->left;
            if (left != nullptr) {
                temp.push(node);
                node->left = nullptr;
                node = left;
            } else {
                result.push_back(node->val);
                TreeNode *right = node->right;
                if (right != nullptr) {
                    node = right;
                } else {
                    if (temp.empty()) {
                        break;
                    }
                    node = temp.top();
                    temp.pop();
                }
            }
        }
        return result;
    }
};
