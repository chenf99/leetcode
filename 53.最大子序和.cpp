/*
 * @lc app=leetcode.cn id=53 lang=cpp
 *
 * [53] 最大子序和
 */

// @lc code=start
#include <vector>
#include <algorithm>
using namespace std;

// 解法一
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        if (!nums.size()) return 0;
        int dp = nums[0]; //dp[i]:以第i个元素为结尾的最大子序和
        int result = dp;
        for (int i = 1; i < nums.size(); ++i) {
            if (dp > 0) dp += nums[i];
            else dp = nums[i];
            result = max(dp, result);
        }
        return result;
    }
};

// 解法二

// @lc code=end

