/*
 * @lc app=leetcode.cn id=64 lang=cpp
 *
 * [64] 最小路径和
 */

// @lc code=start
#include <vector>
using namespace std;

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        if (!grid.size() || !grid[0].size()) return 0;
        int m = grid.size(), n = grid[0].size();
        int dp[n];
        dp[0] = grid[0][0];
        for (int j = 1; j < n; ++j) dp[j] = dp[j - 1] + grid[0][j];
        for (int i = 1; i < m; ++i) {
            dp[0] = grid[i][0] + dp[0];
            for (int j = 1; j < n; ++j) {
                dp[j] = min(dp[j], dp[j - 1]) + grid[i][j];
            }
        }
        return dp[n - 1];
    }
};
// @lc code=end

