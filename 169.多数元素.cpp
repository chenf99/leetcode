/*
 * @lc app=leetcode.cn id=169 lang=cpp
 *
 * [169] 多数元素
 */

// @lc code=start
// 解法一
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int, int> count;
        for (auto i : nums) {
            if (count.find(i) == count.end()) count[i] = 1;
            else count[i]++;
            if (count[i] > nums.size() / 2) return i;
        }
        return INT_MIN;
    }
};

// 解法二
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int candidate = -1, count = 0;
        for (auto x : nums) {
            if (!count) candidate = x;
            if (x == candidate) count++;
            else count--;
        }
        return candidate;
    }
};
// @lc code=end

