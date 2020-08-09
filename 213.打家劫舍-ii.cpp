/*
 * @lc app=leetcode.cn id=213 lang=cpp
 *
 * [213] 打家劫舍 II
 */

// @lc code=start
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;
        if (n == 1) return nums[0];
        if (n == 2) return max(nums[0], nums[1]);
        int dp[n];
        dp[0] = nums[0];
        dp[1] = max(nums[0], nums[1]);
        for (int i = 2; i < n - 1; ++i) dp[i] = max(dp[i - 1], dp[i - 2] + nums[i]);
        int ans = dp[n - 2];
        dp[1] = nums[1];
        dp[2] = max(nums[1], nums[2]);
        for (int i = 3; i < n; ++i) dp[i] = max(dp[i - 1], dp[i - 2] + nums[i]);
        return max(ans, dp[n - 1]);
    }
};
// @lc code=end

