/*
 * @lc app=leetcode.cn id=297 lang=java
 *
 * [297] 二叉树的序列化与反序列化
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
/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */
import java.util.Queue;
import java.util.LinkedList;

public class Codec {
    // Encodes a tree to a single string.
    public String serialize(TreeNode root) {
        if (root == null) return "null";
        Queue<TreeNode> queue = new LinkedList<TreeNode>();
        queue.offer(root);
        StringBuilder ans = new StringBuilder("" + root.val);
        while (!queue.isEmpty()) {
            TreeNode node = queue.poll();
            if (node != null) {
                if (node.left == null) ans.append(",null");
                else ans.append("," + node.left.val);
                if (node.right == null) ans.append(",null");
                else ans.append("," + node.right.val);
                queue.offer(node.left);
                queue.offer(node.right);
            }
        }
        return ans.toString();
    }

    // Decodes your encoded data to tree.
    public TreeNode deserialize(String data) {
        TreeNode root = null;
        int[] index = {0};
        Queue<TreeNode> queue = new LinkedList<TreeNode>();
        Integer num = getNum(data, index);
        if (num != null) {
            root = new TreeNode(num.intValue());
            queue.offer(root);
        }
        while (index[0] < data.length()) {
            int n = queue.size();
            for (int i = 0; i < n; ++i) {
                TreeNode node = queue.poll();
                Integer num1 = getNum(data, index);
                Integer num2 = getNum(data, index);
                if (num1 != null) {
                    node.left = new TreeNode(num1.intValue());
                    queue.offer(node.left);
                }
                if (num2 != null) {
                    node.right = new TreeNode(num2.intValue());
                    queue.offer(node.right);
                }
            }
        }
        return root;
    }

    private Integer getNum(String data, int[] index) {
        Integer ans = null;
        char c = data.charAt(index[0]);
        if (c != 'n') {
            if (c == '-') index[0]++;
            int num = 0;
            while (Character.isDigit(data.charAt(index[0]))) {
                num = num * 10 + data.charAt(index[0]++) - '0';
            }
            index[0]++;
            if (c == '-') num *= -1;
            ans = Integer.valueOf(num);
        }
        else index[0] += 5;
        return ans;
    }
}

// Your Codec object will be instantiated and called as such:
// Codec codec = new Codec();
// codec.deserialize(codec.serialize(root));

// Your Codec object will be instantiated and called as such:
// Codec codec = new Codec();
// codec.deserialize(codec.serialize(root));
// @lc code=end

