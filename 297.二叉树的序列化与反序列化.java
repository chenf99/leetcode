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
        String[] new_data = data.split(",");
        TreeNode root = null;
        int[] index = {0};
        Queue<TreeNode> queue = new LinkedList<TreeNode>();
        Integer num = getNum(new_data, index);
        if (num != null) {
            root = new TreeNode(num.intValue());
            queue.offer(root);
        }
        while (index[0] < new_data.length) {
            int n = queue.size();
            for (int i = 0; i < n; ++i) {
                TreeNode node = queue.poll();
                Integer num1 = getNum(new_data, index);
                Integer num2 = getNum(new_data, index);
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

    private Integer getNum(String[] new_data, int[] index) {
        String str = new_data[index[0]++];
        if (str.equals("null")) return null;
        return Integer.valueOf(str);
    }
}

// Your Codec object will be instantiated and called as such:
// Codec codec = new Codec();
// codec.deserialize(codec.serialize(root));

// Your Codec object will be instantiated and called as such:
// Codec codec = new Codec();
// codec.deserialize(codec.serialize(root));
// @lc code=end

