/*
 * @lc app=leetcode.cn id=10 lang=cpp
 *
 * [10] 正则表达式匹配
 */

// @lc code=start
#include <string>
using std::string;

class Solution {
public:
    bool isMatch(string s, string p) {
        bool dp[s.length() + 1][p.length() + 1]; // dp[i][j]:s前i个字符与p前j个字符是否匹配
        for (int i = 0; i < s.length() + 1; ++i) dp[i][0] = false;
        for (int j = 0; j < p.length() + 1; ++j) dp[0][j] = false;
        dp[0][0] = true;
        for (int i = 0; i <= s.length(); ++i) {
            for (int j = 1; j <= p.length(); ++j) {
                if (p[j - 1] == '*') {
                    if (i == 0 || s[i - 1] != p[j - 2] && p[j - 2] != '.') {
                        dp[i][j] = dp[i][j - 2];
                    }
                    else {
                        dp[i][j] = dp[i][j - 2] || dp[i - 1][j];
                    }
                }
                else if (i == 0) dp[i][j] = false;
                else {
                    dp[i][j] = dp[i - 1][j - 1] && (s[i - 1] == p[j - 1] || p[j - 1] == '.');
                }
            }
        }
        return dp[s.length()][p.length()];
    }
};

// 优化空间复杂度
// class Solution {
// public:
//     bool isMatch(string s, string p) {
//         bool dp[p.length() + 1]; // dp[j]:s前i个字符与p前j个字符是否匹配
//         for (int j = 1; j <= p.length(); ++j) dp[j] = false;
//         dp[0] = true;
//         for (int i = 0; i <= s.length(); ++i) {
//             bool leftNor = dp[0];
//             dp[0] = i == 0 ? true : false;
//             for (int j = 1; j <= p.length(); ++j) {
//                 bool tmp = dp[j];
//                 if (p[j - 1] == '*') {
//                     if (i == 0 || s[i - 1] != p[j - 2] && p[j - 2] != '.') {
//                         dp[j] = dp[j - 2];
//                     }
//                     else {
//                         dp[j] = dp[j - 2] || dp[j];
//                     }
//                 }
//                 else if (i == 0) dp[j] = false;
//                 else {
//                     dp[j] = leftNor && (s[i - 1] == p[j - 1] || p[j - 1] == '.');
//                 }
//                 leftNor = tmp;
//             }
//         }
//         return dp[p.length()];
//     }
// };
// @lc code=end

