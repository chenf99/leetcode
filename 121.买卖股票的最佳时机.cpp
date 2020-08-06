/*
 * @lc app=leetcode.cn id=121 lang=cpp
 *
 * [121] 买卖股票的最佳时机
 */

// @lc code=start
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (!prices.size()) return 0;
        int min = prices[0];
        int profit = 0;
        for (auto num : prices) {
            if (num < min) min = num;
            if (num > min) profit = max(profit, num - min);
        }
        return profit;
    }
};
// @lc code=end

