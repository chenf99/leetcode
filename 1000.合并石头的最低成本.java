/*
 * @lc app=leetcode.cn id=1000 lang=java
 *
 * [1000] 合并石头的最低成本
 */

// @lc code=start
// 解法一
class Solution {
    // 不用Integer.MAX_VALUE,因为Integer.MAX_VALUE + 正数 会溢出变为负数
    private int MAX_VALUE = 99999999; 
    public int mergeStones(int[] stones, int k) {
        int n = stones.length;
        if ((n - 1) % (k - 1) != 0) return -1;
        int[][][] dp = new int[n + 1][n + 1][k + 1];
        int[] sum = new int[n + 1];
        for (int i = 1; i <= n; ++i) sum[i] = sum[i - 1] + stones[i - 1];
        for (int i = 1; i <= n; ++i) {
            for (int j = i; j <= n; ++j) {
                for (int m = 2; m <= k; ++m) dp[i][j][m] = MAX_VALUE;
            }
            dp[i][i][1] = 0;
        }
        for (int len = 2; len <= n; ++len) { // 枚举区间长度
            for (int i = 1; i + len - 1 <= n; ++i) { // 枚举区间起点
                int j = i + len - 1;
                for (int m = 2; m <= k; ++m) { // 枚举堆数
                    for (int p = i; p < j; ++p) {  // 枚举分界点
                        dp[i][j][m]= Math.min(dp[i][j][m], dp[i][p][1] + dp[p + 1][j][m - 1]);
                    }
                }
                dp[i][j][1] = dp[i][j][k] + sum[j] - sum[i - 1];
            }
        }
        return dp[1][n][1];
    }
}

// 解法二
class Solution {
    public int mergeStones(int[] stones, int k) {
        int n = stones.length;
        if ((n - 1) % (k - 1) != 0) return -1;
        int[][] dp = new int[n + 1][n + 1];
        int[] sum = new int[n + 1];
        for (int i = 1; i <= n; ++i) sum[i] = sum[i - 1] + stones[i - 1];
        for (int len = k; len <= n; ++len) { // 枚举区间长度
            for (int i = 1; i + len - 1 <= n; ++i) { // 枚举区间起点
                int j = i + len - 1;
                dp[i][j] = Integer.MAX_VALUE;
                for (int p = i; p < j; p += k - 1) {  // 枚举分界点
                    dp[i][j] = Math.min(dp[i][j], dp[i][p] + dp[p + 1][j]);
                }
                if ((j - i) % (k - 1) == 0) dp[i][j] += sum[j] - sum[i - 1];
            }
        }
        return dp[1][n];
    }
}
// @lc code=end

