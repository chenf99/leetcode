/*
 * @lc app=leetcode.cn id=5 lang=cpp
 *
 * [5] 最长回文子串
 */

// @lc code=start
#include <iostream>
#include <string>
using namespace std;

// 解法一
class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.length();
        if (n == 0) return "";
        bool isPalin[n][n];
        string result(1, s[n - 1]);
        for (int start = n - 1; start >= 0; --start) {
            isPalin[start][start] = true;
            for (int end = start + 1; end < n; ++end) {
                isPalin[start][end] = s[start] == s[end];
                if (end > start + 1) isPalin[start][end] = isPalin[start][end] && isPalin[start + 1][end - 1];
                if (isPalin[start][end] && end - start + 1 > result.length()) 
                    result = s.substr(start, end - start + 1);
            }
        }
        return result;
    }
};

// 解法二
// class Solution {
// public:
//     string longestPalindrome(string s) {
//         int start = 0, end = 0;
//         for (int i = 0; i < s.length(); ++i) {
//             auto [left1, right1] = expandStr(s, i, i);
//             auto [left2, right2] = expandStr(s, i, i + 1);
//             if (right1 - left1 > end - start) {
//                 start = left1;
//                 end = right1;
//             }
//             if (right2 - left2 > end - start) {
//                 start = left2;
//                 end = right2;
//             }
//         }
//         return s.substr(start, end - start + 1);
//     }
// private:
//     pair<int, int> expandStr(string s, int left, int right) {
//         while (left >= 0 && right < s.length() && s[left] == s[right]) {
//             left--;
//             right++;
//         }
//         return {left + 1, right - 1};
//     }
// };
// @lc code=end
