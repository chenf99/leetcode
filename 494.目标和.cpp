/*
 * @lc app=leetcode.cn id=494 lang=cpp
 *
 * [494] 目标和
 */

// @lc code=start
#include <vector>
#include <string>
#include <unordered_map>
using namespace std;

// 解法一
class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int s) {
        unordered_map<string, int> mp;
        return findTarget(nums, s, 0, 0, mp);
    }
private:
    int findTarget(vector<int>& nums, int s, int i, int sum, unordered_map<string, int>& mp) {
        if (i == nums.size()) {
            return sum == s;
        }
        string add = to_string(i + 1) + "," + to_string(sum + nums[i]);
        string sub = to_string(i + 1) + "," + to_string(sum - nums[i]);
        if (!mp.count(add)) mp[add] = findTarget(nums, s, i + 1, sum + nums[i], mp);
        if (!mp.count(sub)) mp[sub] = findTarget(nums, s, i + 1, sum - nums[i], mp);
        return mp[add] + mp[sub];
    }
};

// 解法二
class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int sum = 0;
        for (auto num : nums) sum += num;
        if (sum < abs(target) || (sum + target) % 2 == 1) return 0; 
        return subsets(nums, (sum + target) / 2);
    }
private:
    int subsets(vector<int>& nums, int sum) {
        int n = nums.size();
        int dp[n + 1][sum + 1];
        for (int i = 0; i <= sum; ++i) dp[0][i] = 0;
        dp[0][0] = 1;
        for (int i = 1; i <= n; ++i) {
            for (int j = 0; j <= sum; ++j) {
                if (j >= nums[i - 1]) dp[i][j] = dp[i - 1][j] + dp[i - 1][j - nums[i - 1]];
                else dp[i][j] = dp[i - 1][j];
            }
        }
        return dp[n][sum];
    }
};

// 解法二压缩空间
class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int sum = 0;
        for (auto num : nums) sum += num;
        if (sum < abs(target) || (sum + target) % 2 == 1) return 0; 
        return subsets(nums, (sum + target) / 2);
    }
private:
    int subsets(vector<int>& nums, int sum) {
        int n = nums.size();
        int dp[sum + 1];
        for (int i = 0; i <= sum; ++i) dp[i] = 0;
        dp[0] = 1;
        for (int i = 1; i <= n; ++i) {
            for (int j = sum; j >= 0; --j) {
                if (j >= nums[i - 1]) dp[j] += dp[j - nums[i - 1]];
            }
        }
        return dp[sum];
    }
};
// @lc code=end

