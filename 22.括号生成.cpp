/*
 * @lc app=leetcode.cn id=22 lang=cpp
 *
 * [22] 括号生成
 */

// @lc code=start
#include <vector>
#include <string>
#include <iostream>
using namespace std;

// 解法一
// class Solution {
// public:
//     vector<string> generateParenthesis(int n) {
//         vector<string> result;
//         generateAll(result, 0, 2 * n, new char [2 * n + 1]);
//         return result;
//     }
// private:
//     void generateAll(vector<string>& result, int pos, int length, char current[]) {
//         if (pos == length) {
//             if (isValid(current, length)) {
//                 current[length] = '\0';
//                 result.push_back(current);
//             }
//         }
//         else {
//             current[pos] = '(';
//             generateAll(result, pos + 1, length, current);
//             current[pos] = ')';
//             generateAll(result, pos + 1, length, current);
//         }
//     }
//     bool isValid(char str[], int length) {
//         int left = 0, right = 0;
//         for (int i = 0; i < length; ++i) {
//             if (str[i] == '(') left++;
//             else right++;
//             if (left < right) return false;
//         }
//         return left == right;
//     }
// };

// 解法二
// class Solution {
// public:
//     vector<string> generateParenthesis(int n) {
//         vector<string> result;
//         string tmp = "";
//         generateAll(result, 2 * n, tmp, 0, 0);
//         return result;
//     }
// private:
//     void generateAll(vector<string>& result, int length, string& current, int left, int right) {
//         if (current.length() == length) result.push_back(current);
//         else {
//             if (left < length / 2) {
//                 current += "(";
//                 generateAll(result, length, current, left + 1, right);
//                 current.pop_back();
//             }
//             if (left > right) {
//                 current += ")";
//                 generateAll(result, length, current, left, right + 1);
//                 current.pop_back();
//             }
//         }
//     }
// };

// 解法三
class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<vector<string>> dp(n + 1); // dp[i]:用i对括号可能生成的组合
        dp[0] = {""};
        for (int i = 1; i <= n; ++i) {
            for (int j = 0; j < i; ++j) {
                for (auto str1 : dp[j]) 
                    for (auto str2 : dp[i - j - 1]) 
                        dp[i].push_back("(" + str1 + ")" + str2);  
            }
        }
        return dp[n];
    }
};
// @lc code=end

