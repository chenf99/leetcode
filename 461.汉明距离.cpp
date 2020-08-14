/*
 * @lc app=leetcode.cn id=461 lang=cpp
 *
 * [461] 汉明距离
 */

// @lc code=start
class Solution {
public:
    int hammingDistance(int x, int y) {
        int num = x ^ y;
        int ans = 0;
        while (num) {
            if (num % 2 != 0) ans++;
            num >>= 1;
        }
        return ans;
    }
};
// @lc code=end

