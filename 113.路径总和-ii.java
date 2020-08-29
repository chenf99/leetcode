/*
 * @lc app=leetcode.cn id=113 lang=java
 *
 * [113] 路径总和 II
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */
import java.util.List;
import java.util.LinkedList;

class Solution {
    public List<List<Integer>> pathSum(TreeNode root, int sum) {
        List<List<Integer>> ans = new LinkedList<>();
        backtrack(root, sum, new LinkedList<Integer>(), ans);
        return ans;
    }

    private void backtrack(TreeNode root, int sum, LinkedList<Integer> path, List<List<Integer>> ans) {
        if (root != null) {
            path.add(root.val);
            if (root.left == null && root.right == null && sum == root.val) ans.add(new LinkedList<>(path));
            backtrack(root.left, sum - root.val, path, ans);
            backtrack(root.right, sum - root.val, path, ans);
            path.removeLast();
        }
    }
}
// @lc code=end

