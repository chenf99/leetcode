/*
 * @lc app=leetcode.cn id=581 lang=cpp
 *
 * [581] 最短无序连续子数组
 */

// @lc code=start
#include <vector>
#include <climits>
#include <algorithm>
using namespace std;

class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int n = nums.size();
        if (n <= 1) return 0;
        int left = 0, right = n - 1;
        while (left < right) {
            bool flag1 = false, flag2 = false;
            if (nums[left] <= nums[left + 1]) left++, flag1 = true;
            if (nums[right] >= nums[right - 1]) right--, flag2 = true;
            if (!flag1 && !flag2) break;
        }
        if (left >= right) return 0;
        int num1 = INT_MAX, num2 = INT_MIN;
        for (int i = left; i <= right; ++i) {
            num1 = min(num1, nums[i]);
            num2 = max(num2, nums[i]);
        }
        // 不必更新num2,因为num2必定大于nums[left - 1]: num2 >= nums[left], 而0~left是升序
        while (left > 0) {
            if (num1 < nums[left - 1]) --left;
            else break;
        }
        // 同理不必更新num1
        while (right < n - 1) {
            if (num2 > nums[right + 1]) ++right;
            else break;
        }
        return right - left + 1;
    }
};
// @lc code=end

