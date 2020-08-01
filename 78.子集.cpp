/*
 * @lc app=leetcode.cn id=78 lang=cpp
 *
 * [78] 子集
 */

// @lc code=start
#include <vector>
using std::vector;

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> result = {{}};
        vector<int> tmp;
        dfs(result, nums, tmp, 0);
        return result;
    }
private:
    void dfs(vector<vector<int>>& result, vector<int>& nums, vector<int>& tmp, int start) {
        if (start == nums.size()) return;
        for (int i = start; i < nums.size(); ++i) {
                tmp.emplace_back(nums[i]);
                result.emplace_back(tmp);
                dfs(result, nums, tmp, i + 1);
                tmp.pop_back();
        }
    }
};
// @lc code=end

