/*
 * @lc app=leetcode.cn id=560 lang=cpp
 *
 * [560] 和为K的子数组
 */

// @lc code=start
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, int> mp;
        int ans = 0;
        int pre = 0;
        for (int i = 0; i < n; ++i) {
            mp[pre]++;
            pre += nums[i];
            if (mp.count(pre - k)) ans += mp[pre - k];
        }
        return ans;
    }
};
// @lc code=end

