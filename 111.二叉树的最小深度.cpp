/*
 * @lc app=leetcode.cn id=111 lang=cpp
 *
 * [111] 二叉树的最小深度
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

// 解法一
class Solution {
public:
    int minDepth(TreeNode* root) {
        if (!root) return 0;
        int minLeft = minDepth(root->left);
        int minRight = minDepth(root->right);
        if (!root->left || !root->right) return 1 + minLeft + minRight;
        return 1 + min(minLeft, minRight);
    }
};

// 解法二
// class Solution {
// public:
//     int minDepth(TreeNode* root) {
//         if (!root) return 0;
//         queue<TreeNode*> q;
//         q.push(root);
//         int depth = 1;
//         while (!q.empty()) {
//             int n = q.size();
//             for (int i = 0; i < n; ++i) {
//                 TreeNode* node = q.front();
//                 q.pop();
//                 if (node->left) q.push(node->left);
//                 if (node->right) q.push(node->right);
//                 if (!node->left && !node->right) return depth;
//             }
//             depth++;
//         }
//         return depth;
//     }
// };
// @lc code=end

