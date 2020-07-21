/*
 * @lc app=leetcode.cn id=144 lang=cpp
 *
 * [144] 二叉树的前序遍历
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
#include <vector>
#include <stack>
using namespace std;

// 解法一
// class Solution {
// public:
//     vector<int> preorderTraversal(TreeNode* root) {
//         preorder(root);
//         return result;
//     }
// private:
//     vector<int> result;
//     void preorder(TreeNode* root) {
//         if (!root) return;
//         result.push_back(root->val);
//         preorder(root->left);
//         preorder(root->right);
//     }
// };

// 解法二
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        if (!root) return {};
        vector<int> result;
        stack<TreeNode*> s;
        s.push(root);
        while (!s.empty()) {
            TreeNode* top = s.top();
            result.push_back(top->val);
            s.pop();
            if (top->right) s.push(top->right);
            if (top->left) s.push(top->left);
        }
        return result;
    }
};
// @lc code=end

