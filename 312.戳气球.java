/*
 * @lc app=leetcode.cn id=312 lang=java
 *
 * [312] 戳气球
 */

// @lc code=start
import java.util.Arrays;

// 解法一 记忆化递归
class Solution {
    public int maxCoins(int[] nums) {
        int n = nums.length;
        int[] val = new int[n + 2];
        for (int i = 1; i <= n; ++i) val[i] = nums[i - 1];
        val[0] = val[n + 1] = 1;
        int[][] memo = new int[n + 2][n + 2];
        for (int i = 0; i <= n + 1; ++i) Arrays.fill(memo[i], -1);
        return recursion(val, memo, 0, n + 1);
    }

    private int recursion(int[] val, int[][] memo, int left, int right) {
        if (left >= right - 1) return 0;
        if (memo[left][right] != -1) return memo[left][right];
        for (int i = left + 1; i < right; ++i) {
            int sum = val[left] * val[i] * val[right];
            sum += recursion(val, memo, left, i) + recursion(val, memo, i, right);
            memo[left][right] = Math.max(sum, memo[left][right]);
        }
        return memo[left][right];
    }
}
// @lc code=end

