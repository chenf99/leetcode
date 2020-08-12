/*
 * @lc app=leetcode.cn id=283 lang=cpp
 *
 * [283] 移动零
 */

// @lc code=start
#include <vector>
using std::vector;

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int j = 0;
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] != 0) nums[j++] = nums[i];
        }
        while (j < nums.size()) nums[j++] = 0;
    }
private:
    void swap(int& num1, int& num2) {
        int tmp = num2;
        num2 = num1;
        num1 = tmp;
    }
};
// @lc code=end

