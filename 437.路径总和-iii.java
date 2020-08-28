/*
 * @lc app=leetcode.cn id=437 lang=java
 *
 * [437] 路径总和 III
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
import java.util.ArrayList;
import java.util.HashMap;

// 解法一 算出所有路径和
class Solution {
    private int num = 0;

    public int pathSum(TreeNode root, int target) {
        if (root == null) return 0;
        sum(root, target);
        return num;
    }
    
    private ArrayList<Integer> sum(TreeNode root, int target) {
        ArrayList<Integer> array = null;
        if (root != null) {
            array = new ArrayList<Integer>();
            array.add(root.val);
            if (root.val == target) num++;
            ArrayList<Integer> left = sum(root.left, target);
            ArrayList<Integer> right = sum(root.right, target);
            if (left != null) {
                for (int i = 0; i < left.size(); ++i) {
                    int val = left.get(i) + root.val;
                    array.add(val);
                    if (val == target) num++;
                }
            }
            if (right != null) {
                for (int i = 0; i < right.size(); ++i) {
                    int val = right.get(i) + root.val;
                    array.add(val);
                    if (val == target) num++;
                }
            }
        }
        return array;
    }
}

// 解法二 前缀和 + 回溯
class Solution {;
    public int pathSum(TreeNode root, int target) {
        if (root == null) return 0;
        Map<Integer, Integer> map = new HashMap<Integer, Integer>();
        map.put(0, 1);
        return backtrack(root, map, target, 0);
    }
    
    private int backtrack(TreeNode root, Map<Integer, Integer> map, int target, int prefix) {
        if (root == null) return 0;
        prefix += root.val;
        int res = map.getOrDefault(prefix - target, 0);
        map.put(prefix, map.getOrDefault(prefix, 0) + 1);
        res += backtrack(root.left, map, target, prefix) + backtrack(root.right, map, target, prefix);
        // 这个节点遍历完,返回上一层,则由这个节点计算出的前缀和要减一
        map.put(prefix, map.get(prefix) - 1);
        return res;
    }
}
// @lc code=end

