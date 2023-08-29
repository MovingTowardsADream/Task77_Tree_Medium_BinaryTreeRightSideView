#include <iostream>
#include <vector>

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    std::vector<int> rightSideView(TreeNode* root) {
        std::vector<int> result;
        RightSideView(root, 1, result);
        return result;
    }
    void RightSideView(TreeNode* node, int lvl, std::vector<int>& result) {
        if (node == NULL) {
            return;
        }
        if (result.size() < lvl) {
            result.push_back(node->val);
        }
        else {
            result[lvl - 1] = node->val;
        }
        RightSideView(node->left, lvl + 1, result);
        RightSideView(node->right, lvl + 1, result);
    }
};
