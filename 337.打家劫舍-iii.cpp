/*
 * @lc app=leetcode.cn id=337 lang=cpp
 *
 * [337] 打家劫舍 III
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
    int rob(TreeNode* root) {
        int f = 0, g = 0;
        postorder(root, f, g);
        return max(f, g);
    }
private:
    void postorder(TreeNode* root, int& f, int& g) {
        if (root) {
            int f_l = 0, f_r = 0, g_l = 0, g_r = 0;
            if (root->left) postorder(root->left, f_l, g_l);
            if (root->right) postorder(root->right, f_r, g_r);
            f = g_l + g_r + root->val;
            g = max(f_l, g_l) + max(f_r, g_r);
        }
    }
};
// @lc code=end

