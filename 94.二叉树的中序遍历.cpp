/*
 * @lc app=leetcode.cn id=94 lang=cpp
 *
 * [94] 二叉树的中序遍历
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
//     vector<int> inorderTraversal(TreeNode* root) {
//         vector<int> result;
//         inorder(root, result);
//         return result;
//     }
// private:
//     void inorder(TreeNode* root, vector<int>& result) {
//         if (root) {
//             if (root->left) inorder(root->left, result);
//             result.push_back(root->val);
//             if (root->right) inorder(root->right, result);
//         }
//     }
// };

// 解法二
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> result;
        stack<TreeNode*> s;
        unordered_set<TreeNode*> set;
        if (root) s.push(root);
        while (!s.empty()) {
            TreeNode* top = s.top();
            if (top->left && set.find(top->left) == set.end()) s.push(top->left);
            else {
                result.push_back(top->val);
                set.insert(top);
                s.pop();
                if (top->right) s.push(top->right);
            }
        }
        return result;
    }
};
// @lc code=end

