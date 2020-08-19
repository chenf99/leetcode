/*
 * @lc app=leetcode.cn id=338 lang=cpp
 *
 * [338] 比特位计数
 */

// @lc code=start
#include <vector>
using std::vector;

class Solution {
public:
    vector<int> countBits(int num) {
        vector<int> ans(num + 1, 0);
        for (int i = 1; i <= num; ++i) {
            ans[i] = ans[i >> 1] + i % 2;
        }
        return ans;
    }
};
// @lc code=end

