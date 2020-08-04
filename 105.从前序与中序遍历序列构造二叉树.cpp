/*
 * @lc app=leetcode.cn id=105 lang=cpp
 *
 * [105] 从前序与中序遍历序列构造二叉树
 */

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
#include <unordered_map>
using namespace std;

class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int, int> m;
        for (int i = 0; i < inorder.size(); ++i) m[inorder[i]] = i;
        return helper(m, preorder, 0, preorder.size() - 1, 0, preorder.size() - 1);
    }
private:
    TreeNode* helper(unordered_map<int, int>& m, vector<int>& preorder, int l1, int r1, int l2, int r2) {
        if (l1 > r1) return nullptr;
        TreeNode* root = new TreeNode(preorder[l1]);
        int index = m[preorder[l1]], left_num = index - l2;
        root->left = helper(m, preorder, l1 + 1, l1 + left_num, l2, l1 + left_num - 1);
        root->right = helper(m, preorder, l1 + left_num + 1, r1, l2 + left_num + 1, r2);
        return root;
    }
};
// @lc code=end