/*
 * @lc app=leetcode.cn id=538 lang=cpp
 *
 * [538] 把二叉搜索树转换为累加树
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
    int post = 0;
    TreeNode* convertBST(TreeNode* root) {
        if (!root) return root;
        convertBST(root->right);
        root->val += post;
        post = root->val;
        convertBST(root->left);
        return root;
    }
};
// @lc code=end

