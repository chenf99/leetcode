/*
 * @lc app=leetcode.cn id=647 lang=cpp
 *
 * [647] 回文子串
 */

// @lc code=start
#include <string>
#include <cstring>
using std::string;

// 解法一
class Solution {
public:
    int countSubstrings(string s) {
        int n = s.size();
        if (!n) return 0;
        bool dp[n][n];
        memset(dp, false, sizeof(dp));
        for (int i = 0; i < n; ++i) dp[i][i] = true;
        int ans = 0;
        for (int i = n - 1; i >= 0; --i) {
            for (int j = i; j < n; ++j) {
                if (s[i] == s[j]) {
                    if (j <= i + 2) dp[i][j] = true;
                    else dp[i][j] = dp[i + 1][j - 1];
                }
                if (dp[i][j]) ans++;
            }
        }
        return ans;
    }
};

// 解法二
class Solution {
public:
    int countSubstrings(string s) {
        int n = s.size();
        int ans = n;
        for (int i = 0; i < n; ++i) {
            int l = i - 1, r = i + 1;
            while (l >= 0 && r < n && s[l] == s[r]) {
                ans++;
                l--;
                r++;
            }
            l = i, r = i + 1;
            while (l >= 0 && r < n && s[l] == s[r]) {
                ans++;
                l--;
                r++;
            }
        }
        return ans;
    }
};
// @lc code=end

