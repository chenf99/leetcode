/*
 * @lc app=leetcode.cn id=215 lang=cpp
 *
 * [215] 数组中的第K个最大元素
 */

// @lc code=start
#include <vector>
#include <ctime>
#include <cstdlib>
using std::vector;

// 解法一
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        srand(time(0));
        int left = 0, right = nums.size() - 1;
        int target = nums.size() - k;
        int mid = partition(nums, left, right);
        while (mid != target) {
            if (mid < target) {
                left = mid + 1;
                mid = partition(nums, left, right);
            }
            else {
                right = mid - 1;
                mid = partition(nums, left, right);
            }
        }
        return nums[mid];
    }
private:
    int partition(vector<int>& nums, int left, int right) {
        // 使用随机来加速快排, 效果明显
        int i = rand() % (right - left + 1) + left;
        swap(nums[i], nums[left]);
        int pivot = nums[left], base = left;
        while (left < right) {
            while (left < right && nums[right] >= pivot) right--;
            while (left < right && nums[left] <= pivot) left++;
            swap(nums[left], nums[right]);
        }
        nums[base] = nums[left];
        nums[left] = pivot;
        return left;
    }

    void swap(int& num1, int& num2) {
        int tmp = num1;
        num1 = num2;
        num2 = tmp;
    }
};

// 解法二

// @lc code=end

