/*
 * @lc app=leetcode.cn id=543 lang=cpp
 *
 * [543] 二叉树的直径
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
    int diameter = 0;
    int diameterOfBinaryTree(TreeNode* root) {
        depth(root);
        return diameter;
    }
private:
    int depth(TreeNode* root) {
        if (!root) return 0;
        int left = depth(root->left), right = depth(root->right);
        diameter = max(diameter, left + right);
        return 1 + max(left, right);
    }
};
// @lc code=end

