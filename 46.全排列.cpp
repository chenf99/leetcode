/*
 * @lc app=leetcode.cn id=46 lang=cpp
 *
 * [46] 全排列
 */

// @lc code=start
#include <vector>
#include <list>
using namespace std;

class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> permutation;
        vector<bool> used(nums.size(), false);
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

