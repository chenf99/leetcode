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
// struct Status{
//     int l_sum, r_sum, m_sum, i_sum;
// };

// class Solution {
// public:
//     int maxSubArray(vector<int>& nums) {
//         return getSum(nums, 0, nums.size() - 1).m_sum;
//     }
// private:
//     Status getSum(const vector<int>& nums, int l, int r) {
//         if (l == r) return Status{nums[l], nums[l], nums[l], nums[l]};
//         int m = (l + r) / 2;
//         Status s1 = getSum(nums, l, m);
//         Status s2 = getSum(nums, m + 1, r);
//         int i_sum = s1.i_sum + s2.i_sum;
//         int l_sum = max(s1.l_sum, s1.i_sum + s2.l_sum);
//         int r_sum = max(s2.r_sum, s1.r_sum + s2.i_sum);
//         int m_sum = max(max(s1.m_sum, s2.m_sum), s1.r_sum + s2.l_sum);
//         return Status{l_sum, r_sum, m_sum, i_sum};
//     }
// };
// @lc code=end

