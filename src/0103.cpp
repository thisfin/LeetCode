//
// Created by 李毅 on 2021/3/16.
//

#include <deque>
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
    vector<vector<int>> zigzagLevelOrder(TreeNode *root) { // 利用 deque 双向插入， 单 queue 利用 size 遍历
        vector<vector<int>> result = vector<vector<int>>();
        if (root == nullptr) {
            return result;
        }
        queue<TreeNode *> nodeQueue;
        bool rightBegin = false;
        nodeQueue.push(root);
        for (; !nodeQueue.empty();) {
            deque<int> line;
            int size = nodeQueue.size();
            for (int i = 0; i < size; ++i) {
                TreeNode *node = nodeQueue.front();
                nodeQueue.pop();
                if (rightBegin) {
                    line.push_front(node->val);
                } else {
                    line.push_back(node->val);
                }
                if (node->left != nullptr) {
                    nodeQueue.push(node->left);
                }
                if (node->right != nullptr) {
                    nodeQueue.push(node->right);
                }
            }
            rightBegin = !rightBegin;
            result.emplace_back(vector<int>(line.begin(), line.end())); // 比 push_back 快
        }
        return result;
    }

    vector<vector<int>> zigzagLevelOrderOld(TreeNode *root) { // 双栈替换
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