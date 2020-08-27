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

// 解法二 dp
class Solution {
    public int maxCoins(int[] nums) {
        int n = nums.length;
        int[] val = new int[n + 2];
        for (int i = 1; i <= n; ++i) val[i] = nums[i - 1];
        val[0] = val[n + 1] = 1;
        int[][] dp = new int[n + 2][n + 2];
        for (int i = 0; i <= n + 1; ++i) Arrays.fill(dp[i], -1);
        for (int i = n + 1; i >= 0; --i) {
            for (int j = i + 1; j <= n + 1; ++j) {
                if (j == i + 1) dp[i][j] = 0;
                else {
                    for (int k = i + 1; k < j; ++k) {
                        int sum = val[i] * val[k] * val[j];
                        sum += dp[i][k] + dp[k][j];
                        dp[i][j] = Math.max(dp[i][j], sum);
                    }
                }
            }
        }
        return dp[0][n + 1];
    }
}
// @lc code=end

