/*
 * @lc app=leetcode.cn id=236 lang=cpp
 *
 * [236] 二叉树的最近公共祖先
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
    TreeNode* node = NULL;
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        findChild(root, p, q);
        return node;
    }
private:
    bool findChild(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (!root) return false;
        bool left = findChild(root->left, p, q), right = findChild(root->right, p, q);
        // p和q分别在root的左右两个子树中
        if (left && right) {
            node = root;
            return true;
        }
        bool flag1 = root == p || root == q;
        bool flag2 = left || right;
        // p和q一个是root，一个在root的子树中
        if (flag1 && flag2) {
            node = root;
            return true;
        }
        return flag1 || flag2;
    }
};

// 解法二
// class Solution {
// public:
//     unordered_map<int, TreeNode*> parent;
//     TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
//         dfs(root);
//         parent[root->val] = nullptr;
//         unordered_map<int, bool> visit;
//         TreeNode* tmp = p;
//         while (tmp != nullptr) {
//             visit[tmp->val] = true;
//             tmp = parent[tmp->val];
//         }
//         tmp = q;
//         while (tmp != nullptr) {
//             if (visit[tmp->val]) return tmp;
//             tmp = parent[tmp->val];
//         }
//         return nullptr;
//     }
// private:
//  void dfs(TreeNode* root) {
//     if (root->left) {
//         parent[root->left->val] = root;
//         dfs(root->left);
//     }
//     if (root->right) {
//         parent[root->right->val] = root;
//         dfs(root->right);
//     }
//  }
// };
// @lc code=end

