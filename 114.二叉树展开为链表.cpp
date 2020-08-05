/*
 * @lc app=leetcode.cn id=114 lang=cpp
 *
 * [114] 二叉树展开为链表
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

// 解法一
// class Solution {
// public:
//     void flatten(TreeNode* root) {
//         stack<TreeNode*> s;
//         TreeNode* prev = nullptr;
//         if (root) s.push(root);
//         while (!s.empty()) {
//             TreeNode* node = s.top();
//             s.pop();
//             if (prev) {
//                 prev->left = nullptr;
//                 prev->right = node;
//             }
//             prev = node;
//             if (node->right) s.push(node->right);
//             if (node->left) s.push(node->left);
//         }
//     }
// };

// 解法二
class Solution {
public:
    void flatten(TreeNode* root) {
        TreeNode* node = root;
        while (node) {
            TreeNode* prev = node->left;
            if (prev) {
                while (prev->right) prev = prev->right;
                prev->right = node->right;
                node->right = node->left;
                node->left = nullptr;
            }
            node = node ->right;
        }
    }
};
// @lc code=end

