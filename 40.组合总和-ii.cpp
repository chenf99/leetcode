/*
 * @lc app=leetcode.cn id=40 lang=cpp
 *
 * [40] 组合总和 II
 */

// @lc code=start
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> result;
        sort(candidates.begin(), candidates.end());
        vector<int> solution;
        dfs(result, candidates, solution, target, 0);
        return result;
    }
private:
    void dfs(vector<vector<int>>& result, const vector<int>& candidates, vector<int>& solution,\
        const int& target, int start) {
        if (target == 0) result.emplace_back(solution);
        for (int i = start; i < candidates.size() && target - candidates[i] >= 0; ++i) {
            // i > start保证只剪枝同一层的
            if (i > start && candidates[i] == candidates[i - 1]) continue;
            solution.emplace_back(candidates[i]);
            dfs(result, candidates, solution, target - candidates[i], i + 1);
            solution.pop_back();
        }
    }
};
// @lc code=end

