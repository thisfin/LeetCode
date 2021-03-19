//
// Created by 李毅 on 2021/3/18.
//

#include <limits>
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
    vector<int> preorderTraversal(TreeNode *root) {
        vector<int> result;
        TreeNode *node = root;
        for (; node != nullptr;) {
            if (node->left != nullptr) {
                TreeNode *temp = node->left;
                for (; temp->right != nullptr && temp->right != node;) {
                    temp = temp->right;
                }
                if (temp->right == node) {
                    node = node->right;
                    continue;
                }
                temp->right = node;
                result.emplace_back(node->val);
                temp = node->left;
                node = temp;
            } else {
                result.emplace_back(node->val);
                node = node->right;
            }
        }
        return result;
    }

    vector<int> preorderTraversalOld(TreeNode *root) {
        vector<int> result;
        TreeNode *node = root;
        for (; node != nullptr;) {
            if (node->val != numeric_limits<int>::min()) {
                result.push_back(node->val);
                node->val = numeric_limits<int>::min();
            }
            if (node->left != nullptr) {
                TreeNode *temp = node->left;
                for (; temp->right != nullptr;) {
                    temp = temp->right;
                }
                temp->right = node;
                temp = node->left;
                node->left = nullptr;
                node = temp;
            } else {
                result.emplace_back(node->val);
                node = node->right;
            }
        }
        return result;
    }
};
