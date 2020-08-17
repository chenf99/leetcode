/*
 * @lc app=leetcode.cn id=110 lang=cpp
 *
 * [110] 平衡二叉树
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
    bool isBalanced(TreeNode* root) {
        depth(root);
        return is_balanced;
    }
private:
    bool is_balanced = true;
    int depth(TreeNode* root) {
        if (!root) return 0;
        int left = depth(root->left);
        int right = depth(root->right);
        if (abs(left - right) > 1) is_balanced = false;
        return 1 + max(left, right);
    }
};
// @lc code=end

