/*
 * @lc app=leetcode.cn id=123 lang=java
 *
 * [123] 买卖股票的最佳时机 III
 */

// @lc code=start
class Solution {
    public int maxProfit(int[] prices) {
        int dp_1_0 = 0, dp_1_1 = Integer.MIN_VALUE, dp_2_0 = 0, dp_2_1 = Integer.MIN_VALUE;
        for (int i = 0; i < prices.length; ++i) {
                dp_2_0 = Math.max(dp_2_0, dp_2_1 + prices[i]);
                dp_2_1 = Math.max(dp_2_1, dp_1_0 - prices[i]);
                dp_1_0 = Math.max(dp_1_0, dp_1_1 + prices[i]);
                dp_1_1 = Math.max(dp_1_1, -prices[i]);
        }
        return dp_2_0;
    }
}
// @lc code=end

