/*
 * @lc app=leetcode.cn id=98 lang=cpp
 *
 * [98] 验证二叉搜索树
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
#include <iostream>
#include <climits>
using namespace std;

// 解法一
// class Solution {
// public:
//     bool isValidBST(TreeNode* root) {
//         long long left = LONG_MIN, right = LONG_MAX;
//         return helper(root, left, right); 
//     }
// private:
//     bool helper(TreeNode* root, long long left, long long right) {
//         if (!root) return true;
//         if (root->val <= left || root->val >= right) return false;
//         return helper(root->left, left, root->val) && helper(root->right, root->val, right);
//     }
// };

// 解法二
// 利用中序遍历的思想，中序遍历的下一个节点是它右子树的最左叶子节点
class Solution {
public:
    long long pre = LONG_MIN;
    bool isValidBST(TreeNode* root) {
        if (!root) return true;
        if (!isValidBST(root->left)) return false;
        if (root->val <= pre) return false;
        pre = root->val;
        return isValidBST(root->right);
    }
};
// @lc code=end

