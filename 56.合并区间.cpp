/*
 * @lc app=leetcode.cn id=56 lang=cpp
 *
 * [56] 合并区间
 */

// @lc code=start
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n = intervals.size();
        if (!n) return {};
        vector<vector<int>> result;
        sort(intervals.begin(), intervals.end(), compare);
        int left = intervals[0][0], right = intervals[0][1];
        for (int i = 1; i < n; ++i) {
            if (right >= intervals[i][0] && right < intervals[i][1]) {
                right = intervals[i][1];
            }
            else if (right < intervals[i][0]) {
                result.push_back({left, right});
                left = intervals[i][0];
                right = intervals[i][1];
            }
        }
        result.push_back({left, right});
        return result;
    }
private:
    static bool compare(vector<int>& inter1, vector<int>& inter2) {
        return inter1[0] < inter2[0];
    }
};
// @lc code=end

