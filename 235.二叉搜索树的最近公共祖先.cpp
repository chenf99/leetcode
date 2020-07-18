/*
 * @lc app=leetcode.cn id=235 lang=cpp
 *
 * [235] 二叉搜索树的最近公共祖先
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
#include <algorithm>
using namespace std;

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (p == root || q == root) return root;
        int val1 = min(p->val, q->val);
        int val2 = max(p->val, q->val);
        if (val1 < root->val && val2 > root->val) return root;
        if (val2 < root->val) return lowestCommonAncestor(root->left, p, q);
        return lowestCommonAncestor(root->right, p, q);
    }
};
// @lc code=end

