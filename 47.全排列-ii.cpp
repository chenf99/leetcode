/*
 * @lc app=leetcode.cn id=47 lang=cpp
 *
 * [47] 全排列 II
 */

// @lc code=start
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> permutation;
        vector<bool> used(nums.size(), false);
        sort(nums.begin(), nums.end());
        dfs(result, permutation, nums, used);
        return result;
    }
private:
    void dfs(vector<vector<int>>& result, vector<int>& permutation, const vector<int>& nums, vector<bool>& used) {
        if (permutation.size() == nums.size()) {
            result.emplace_back(permutation);
            return;
        }
        for (int i = 0; i < nums.size(); ++i) {
            if (i > 0 && nums[i] == nums[i - 1] && !used[i - 1]) continue;
            if (!used[i]) {
                permutation.emplace_back(nums[i]);
                used[i] = true;
                dfs(result, permutation, nums, used);
                permutation.pop_back();
                used[i] = false;
            }
        }
    }
};
// @lc code=end

