/*
 * @lc app=leetcode.cn id=617 lang=cpp
 *
 * [617] 合并二叉树
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
    TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {
        if (!t1 && !t2) return nullptr;
        int val = 0;
        TreeNode *left1 = nullptr, *left2 = nullptr;
        TreeNode *right1 = nullptr, *right2 = nullptr;
        if (t1) {
            val += t1->val;
            left1 = t1->left;
            right1 = t1->right;
        }
        if (t2) {
            val += t2->val;
            left2 = t2->left;
            right2 = t2->right;
        }
        TreeNode* root = new TreeNode(val);
        root->left = mergeTrees(left1, left2);
        root->right = mergeTrees(right1, right2);
        return root;
    }
};
// @lc code=end

