/*
 * @lc app=leetcode.cn id=101 lang=cpp
 *
 * [101] 对称二叉树
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        if (!root) return true;
        return symmetric(root->left, root->right);
    }
private:
    bool symmetric(TreeNode* root1, TreeNode* root2) {
        if (!root1 && !root2) return true;
        if (root1 && root2 && root1->val == root2->val) {
            return symmetric(root1->left, root2->right) && symmetric(root1->right, root2->left);
        }
        return false;
    }
};
// @lc code=end

