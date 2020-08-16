/*
 * @lc app=leetcode.cn id=448 lang=cpp
 *
 * [448] 找到所有数组中消失的数字
 */

// @lc code=start
#include <vector>
#include <cmath>
using std::vector;

class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans;
        for (int i = 0; i < n; ++i) {
            int index = std::abs(nums[i]);
            if (nums[index - 1] > 0) nums[index - 1] *= -1;
        }
        for (int i = 0; i < n; ++i) {
            if (nums[i] > 0) ans.push_back(i + 1);
        }
        return ans;
    }
};
// @lc code=end

