/*
 * @lc app=leetcode.cn id=221 lang=cpp
 *
 * [221] 最大正方形
 */

// @lc code=start
class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        if (matrix.size() == 0) return 0;
        int n = matrix[0].size();
        vector<int> left(n, 0), right(n, n), height(n, 0);
        int result = 0;
        for (int i = 0; i < matrix.size(); ++i) {
            int curLeft = 0, curRight = n;
            for (int j = 0; j < n; ++j) {
                if (matrix[i][j] == '1') {
                    height[j] = height[j] + 1;
                    left[j] = max(curLeft, left[j]);
                }
                else {
                    curLeft = j + 1;
                    left[j] = 0;
                    height[j] = 0;
                }
            }
            for (int j = n - 1; j >= 0; --j) {
                if (matrix[i][j] == '1') {
                    right[j] = min(curRight, right[j]);
                    int width = right[j] - left[j];
                    result = max(result, min(width, height[j]) * min(width, height[j]));
                }
                else {
                    curRight = j;
                    right[j] = n;
                }
            }
        }
        return result;
    }
};
// @lc code=end

