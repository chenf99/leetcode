/*
 * @lc app=leetcode.cn id=145 lang=cpp
 *
 * [145] 二叉树的后序遍历
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
#include <unordered_set>
using namespace std;

// 解法一
// class Solution {
// public:
//     vector<int> postorderTraversal(TreeNode* root) {
//         vector<int> result;
//         postorder(root, result);
//         return result;
//     }
// private:
//     void postorder(TreeNode* root, vector<int>& result) {
//         if (root) {
//             if (root->left) postorder(root->left, result);
//             if (root->right) postorder(root->right, result);
//             result.push_back(root->val);
//         }
//     }
// };

//解法二
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> result;
        unordered_set<TreeNode*> set;
        stack<TreeNode*> s;
        if (root) s.push(root);
        while (!s.empty()) {
            TreeNode* top = s.top();
            bool flag1 = true, flag2 = true;
            if (top->right && set.find(top->right) == set.end()) {
                s.push(top->right);
                flag1 = false;
            }
            if (top->left && set.find(top->left) == set.end()) {
                s.push(top->left);
                flag2 = false;
            }
            if (flag1 && flag2) {
                result.push_back(top->val);
                set.insert(top);
                s.pop();
            }
        }
        return result;
    }
};
// @lc code=end

