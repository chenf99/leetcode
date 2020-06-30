/*
 * @lc app=leetcode.cn id=70 lang=cpp
 *
 * [70] 爬楼梯
 */

// @lc code=start
class Solution {
public:
    int climbStairs(int n) {
        if (n == 1) return 1;
        else if (n == 2) return 2;
        int a[n];
        a[0] = 1;
        a[1] = 2;
        for (int i = 2; i < n; ++i) 
            a[i] = a[i-1] + a[i-2];
        return a[n-1];
    }
};
// @lc code=end

