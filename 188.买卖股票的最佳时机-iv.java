/*
 * @lc app=leetcode.cn id=188 lang=java
 *
 * [188] 买卖股票的最佳时机 IV
 */

// @lc code=start
class Solution {
    public int maxProfit(int k, int[] prices) {
        if (k >= prices.length / 2) { // 最多进行n/2笔交易
            int profit = 0;
            for (int i = 1; i < prices.length; ++i) {
                if (prices[i] > prices[i - 1]) profit += prices[i] - prices[i - 1];
            }
            return profit;
        }
        int[] dp_0 = new int[k + 1], dp_1 = new int[k + 1];
        for (int i = 0; i <= k; ++i) {
            dp_0[i] = 0;
            dp_1[i] = Integer.MIN_VALUE;
        }
        for (int i = 0; i < prices.length; ++i) {
            for (int j = 1; j <= k; ++j) {
                dp_0[j] = Math.max(dp_0[j], dp_1[j] + prices[i]);
                dp_1[j] = Math.max(dp_1[j], dp_0[j - 1] - prices[i]);
            }
        }
        return dp_0[k];
    }
}
// @lc code=end

