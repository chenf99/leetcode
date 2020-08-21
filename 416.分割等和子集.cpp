/*
 * @lc app=leetcode.cn id=416 lang=cpp
 *
 * [416] 分割等和子集
 */

// @lc code=start
#include <vector>
using std::vector;

class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for (auto num : nums) sum += num;
        if (sum & 1 == 1) return false;
        sum /= 2;
        int n = nums.size();
        bool dp[n + 1][sum + 1];  // dp[i][j]: 前i个数字是否能分割出和等于j的子集
        for (int i = 0; i <= sum; ++i) dp[0][i] = false;
        for (int i = 0; i <= n; ++i) dp[i][0] = true;
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= sum; ++j) {
                if (j >= nums[i - 1]) dp[i][j] = dp[i - 1][j] || dp[i - 1][j - nums[i - 1]];
                else dp[i][j] = dp[i - 1][j];
                
            }
        }
        return dp[n][sum];
    }
};

// 压缩空间
class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for (auto num : nums) sum += num;
        if (sum & 1 == 1) return false;
        sum /= 2;
        int n = nums.size();
        bool dp[sum + 1];  // dp[i][j]: 前i个数字是否能分割出和等于j的子集
        for (int i = 1; i <= sum; ++i) dp[i] = false;
        dp[0] = true;
        for (int i = 1; i <= n; ++i) {
            for (int j = sum; j >= 1; --j) {
                if (j >= nums[i - 1]) dp[j] = dp[j] || dp[j - nums[i - 1]];
            }
        }
        return dp[sum];
    }
};
// @lc code=end

