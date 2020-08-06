/*
 * @lc app=leetcode.cn id=124 lang=cpp
 *
 * [124] 二叉树中的最大路径和
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
class Solution {
public:
    int maxPathSum(TreeNode* root) {
        maxGain(root);
        return max_sum;
    }
private:
    int max_sum = INT_MIN;
    int maxGain(TreeNode* root) {
        if (!root) return 0;
        int left_gain = max(maxGain(root->left), 0), right_gain = max(maxGain(root->right), 0);
        max_sum = max(max_sum, root->val + left_gain + right_gain);
        return root->val + max(left_gain, right_gain);
    }
};
// @lc code=end

