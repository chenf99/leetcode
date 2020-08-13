/*
 * @lc app=leetcode.cn id=322 lang=cpp
 *
 * [322] 零钱兑换
 */

// @lc code=start
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

// 解法一
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount + 1, INT_MAX);
        dp[0] = 0;
        for (int i = 1; i <= amount; ++i) {
            for (auto coin : coins) {
                if (i >= coin && dp[i - coin] != -1) dp[i] = min(dp[i], 1 + dp[i - coin]);
            }
            if (dp[i] == INT_MAX) dp[i] = -1;
        }
        return dp[amount];
    }
};

// 解法二
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        sort(coins.rbegin(), coins.rend());
        int ans = INT_MAX, count = 0;
        backtrack(coins, amount, ans, count, 0);
        return ans == INT_MAX ? -1 : ans;
    }
private:
    void backtrack(vector<int>& coins, int amount, int& ans, int& count, int index) {
        if (amount == 0) {
            ans = min(ans, count);
            return;
        }
        if (index == coins.size()) return;
        for (int k = amount / coins[index]; k >= 0 && k + count < ans; --k) {
            count += k;
            amount -= k * coins[index];
            backtrack(coins, amount, ans, count, index + 1);
            count -= k;
            amount += k * coins[index];
        }
    }
};
// @lc code=end