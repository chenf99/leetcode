/*
 * @lc app=leetcode.cn id=55 lang=cpp
 *
 * [55] 跳跃游戏
 */

// @lc code=start
#include <vector>
using std::vector;

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        if (!n) return false;
        int len = nums[0];
        for (int i = 1; i <= len && i < n; ++i) {
            if (nums[i] > len - i) len = i + nums[i];
        }
        return len >= n - 1;
    }
};
// @lc code=end

