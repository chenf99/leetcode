/*
 * @lc app=leetcode.cn id=139 lang=cpp
 *
 * [139] 单词拆分
 */

// @lc code=start
#include <vector>
#include <string>
#include <unordered_set>
#include <cstring>
using namespace std;

// 解法一
// class Solution {
// public:
//     bool wordBreak(string s, vector<string>& wordDict) {
//         unordered_set<string> set;
//         backtrack(s, wordDict, set);
//         return result;
//     }
// private:
//     bool result = false;
//     void backtrack(string& s, vector<string>& wordDict, unordered_set<string>& set) {
//         if (s.size() == 0) {
//             result = true;
//             return;
//         }
//         for (auto& word : wordDict) {
//             int n = word.size();
//             string s1 = s.substr(0, n);
//             if (s1 == word) {
//                 s = s.substr(n);
//                 if (!set.count(s)) {
//                     backtrack(s, wordDict, set);
//                     set.insert(s);
//                 }
//                 s = s1 + s;
//             }
//         }
//     }
// };

// 解法二
class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.size();
        bool dp[n + 1];
        memset(dp, false, sizeof(dp));
        dp[0] = true;
        for (int i = 1; i <= n; ++i) {
            for (auto& word : wordDict) {
                int m = word.size();
                if (i >= m && s.substr(i - m, m) == word) dp[i] = dp[i] | dp[i - m];
            }
        }
        return dp[n];
    }
};
// @lc code=end

