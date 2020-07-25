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
        list<int> l(nums.begin(), nums.end());
        dfs(result, permutation, l);
        return result;
    }
private:
    void dfs(vector<vector<int>>& result, vector<int>& permutation, list<int> l) {
        if (!l.size()) {
            result.push_back(permutation);
            return;
        }
        for (auto it = l.begin(); it != l.end(); ) {
            int tmp = *it;
            permutation.push_back(*it);
            it = l.erase(it);
            dfs(result, permutation, l);
            l.insert(it, tmp);
            permutation.pop_back();
        }
    }
};
// @lc code=end

