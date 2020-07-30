/*
 * @lc app=leetcode.cn id=49 lang=cpp
 *
 * [49] 字母异位词分组
 */

// @lc code=start
#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> result;
        unordered_map<string, vector<string>> m;
        for (auto& s : strs) {
            string key = s;
            sort(key.begin(), key.end());
            if (!m.count(key)) m[key] = {};
            m[key].emplace_back(s);
        }
        for (auto& it : m) result.emplace_back(it.second);
        return result;
    }
};
// @lc code=end

