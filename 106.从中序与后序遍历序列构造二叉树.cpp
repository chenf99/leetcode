/*
 * @lc app=leetcode.cn id=106 lang=cpp
 *
 * [106] 从中序与后序遍历序列构造二叉树
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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        unordered_map<int, int> m;
        for (int i = 0; i < inorder.size(); ++i) m[inorder[i]] = i;
        return helper(m, postorder, 0, inorder.size() - 1, 0, inorder.size() - 1);
    }
private:
    TreeNode* helper(unordered_map<int, int>& m, vector<int>& postorder, int l1, int r1, int l2, int r2) {
        if (l1 > r1) return nullptr;
        TreeNode* root = new TreeNode(postorder[r2]);
        int index = m[postorder[r2]], left_num = index - l1;
        root->left = helper(m, postorder, l1, l1 + left_num - 1, l2, l2 + left_num - 1);
        root->right = helper(m, postorder, l1 + left_num + 1, r1, l2 + left_num, r2 - 1);
        return root;
    }
};

// 解法二
// class Solution {
// public:
//     TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
//         int n = inorder.size();
//         if (!n) return nullptr;
//         int post_index = n - 1, in_index = n - 1;
//         TreeNode* root = new TreeNode(postorder[post_index--]);
//         stack<TreeNode*> s;
//         s.push(root);
//         while (post_index >= 0) {
//             TreeNode* node = s.top();
//             TreeNode* tmp = new TreeNode(postorder[post_index--]);
//             if (node->val != inorder[in_index]) node->right = tmp;
//             else {
//                 while (!s.empty() && s.top()->val == inorder[in_index]) {
//                     node = s.top();
//                     s.pop();
//                     in_index--;
//                 }
//                 node->left = tmp;
//             }
//             s.push(tmp);
//         }
//         return root;
//     }
// };
// @lc code=end

