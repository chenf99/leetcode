/*
 * @lc app=leetcode.cn id=75 lang=cpp
 *
 * [75] 颜色分类
 */

// @lc code=start
#include <vector>
using std::vector;

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int left = 0, right = nums.size() - 1;
        int curr = 0;
        while (curr <= right) {
            if (nums[curr] == 0) swap(nums[left++], nums[curr++]);
            else if (nums[curr] == 2) swap(nums[right--], nums[curr]);
            else curr++;
        }
    }
private:
    void swap(int& num1, int& num2) {
        int tmp = num2;
        num2 = num1;
        num1 = tmp;
    }
};
// @lc code=end

