/*
 * @lc app=leetcode.cn id=153 lang=cpp
 *
 * [153] 寻找旋转排序数组中的最小值
 */

// @lc code=start
#include <vector>
using namespace std;

class Solution {
public:
    int findMin(vector<int>& nums) {
        int left = 0, right = nums.size() - 1;
        while (left < right) {
            int mid = (left + right) / 2;
            if (nums[mid] > nums[right]) left = mid + 1; // [l, mid]有序,，最小值在(mid, r]中
            else right = mid; // [mid, r]有序,最小值在[l,mid]中
        }
        return nums[left];
    }
};
// @lc code=end

