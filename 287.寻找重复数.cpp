/*
 * @lc app=leetcode.cn id=287 lang=cpp
 *
 * [287] 寻找重复数
 */

// @lc code=start
#include <vector>
using std::vector;

// 解法一
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n = nums.size() - 1;
        int left = 1, right = n;
        while (left < right) {
            int count = 0, mid = (left + right) / 2;
            for (auto num : nums) {
                if (num <= mid) count++;
            }
            if (count > mid) right = mid;
            else left = mid + 1;
        }
        return left;
    }
};

// 解法二
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n = nums.size() - 1;
        int slow = 0, fast = 0;
        do {
            slow = nums[slow];
            fast = nums[nums[fast]];
        } while (slow != fast);
        slow = 0;
        while (slow != fast) {
            slow = nums[slow];
            fast = nums[fast];
        }
        return slow;
    }
};
// @lc code=end

