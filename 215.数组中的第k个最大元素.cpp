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
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int n = nums.size();
        buildMaxHeap(nums);
        for (int i = n - 1; i >= (int)nums.size() - k; --i) {
            swap(nums[0], nums[i]);
            n--;
            heapify(nums, 0, n);
        }
        return nums[nums.size() - k];
    }
private:
    void buildMaxHeap(vector<int>& nums) {
        for (int i = nums.size() / 2 - 1; i >= 0; --i) {
            heapify(nums, i, nums.size());
        }
    }

    void heapify(vector<int>& nums, int i, int n) {
        int left = 2 * i + 1;
        int right = 2 * i + 2;
        int largestIndex = i;
        if (left < n && nums[largestIndex] < nums[left]) largestIndex = left;
        if (right < n && nums[largestIndex] < nums[right]) largestIndex = right;
        if (largestIndex != i) {
            swap(nums[largestIndex], nums[i]);
            heapify(nums, largestIndex, n);
        }
    }

    void swap(int& num1, int& num2) {
        int tmp = num1;
        num1 = num2;
        num2 = tmp;
    }
};
// @lc code=end

