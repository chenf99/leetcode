/*
 * @lc app=leetcode.cn id=39 lang=cpp
 *
 * [39] 组合总和
 */

// @lc code=start
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> result;
        vector<int> permut;
        sort(candidates.begin(), candidates.end());
        dfs(result, candidates, target, permut, 0);
        return result;
    }
private:
    void dfs(vector<vector<int>>& result, const vector<int>& candidates, const int& target, \
        vector<int>& permut, int start) {
        if (target == 0) result.emplace_back(permut);
        for (int i = start; i < candidates.size() && target - candidates[i] >= 0; ++i) {
            permut.emplace_back(candidates[i]);
            dfs(result, candidates, target - candidates[i], permut, i);
            permut.pop_back();
        }
    }
};
// @lc code=end

