/*
 * @lc app=leetcode.cn id=122 lang=java
 *
 * [122] 买卖股票的最佳时机 II
 */

// @lc code=start
class Solution {
    public int maxProfit(int[] prices) {
        int buy = 0, profit = 0;
        for (int i = 1; i < prices.length; ++i) {
            if (prices[i] > prices[buy]) profit += prices[i] - prices[buy];
            buy = i;
        }
        return profit;
    }
}
// @lc code=end

