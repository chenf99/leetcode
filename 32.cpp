/*
Given a string containing just the characters '(' and ')', 
find the length of the longest valid (well-formed) parentheses substring.

Example 1:

Input: "(()"
Output: 2
Explanation: The longest valid parentheses substring is "()"

Example 2:

Input: ")()())"
Output: 4
Explanation: The longest valid parentheses substring is "()()"
*/

#include<iostream>
#include<string>
#include<stack>
#include<vector>
using namespace std;

// 解法一
// class Solution {
// public:
//     int longestValidParentheses(string str) {
//         int result = 0, start = 0;
//         stack<int> s;
//         for (int i = 0; i < str.size(); ++i) {
//             if (str[i] == '(') s.push(i);
//             else {
//                 if (s.empty()) start = i + 1;
//                 else {
//                     s.pop();
//                     if (s.empty()) result = max(result, i - start + 1);
//                     else result = max(result, i - s.top());
//                 }
//             }
//         }
//         return result;
//     }
// };

// 解法二
class Solution {
public:
    int longestValidParentheses(string s) {
        if (s.length() <= 1) return 0;
        vector<int> dp(s.length(), 0);
        int result = 0;
        for (int i = 0; i < s.length(); ++i) {
            if (s[i] == '(') continue;
            else {
                if (i >= 1 && s[i - 1] == '(') dp[i] = 2 + (i >= 2 ? dp[i - 2] : 0);
                else if (i >= 1 && s[i - 1] == ')') {
                    if (i - dp[i - 1] >= 1 && s[i - dp[i - 1] - 1] == '(') {
                        dp[i] = 2 + dp[i - 1] + (i - dp[i - 1] >= 2 ? dp[i - dp[i - 1] - 2] : 0);
                    }
                }
                result = max(result, dp[i]);
            }
        }
        return result;
    }
};

// 解法三
// class Solution {
// public:
//     int longestValidParentheses(string s) {
//         int left = 0, right = 0;
//         int result = 0;
//         for (auto i : s) {
//             if (i == '(') left++;
//             else right++;
//             if (left == right) result = max(result, 2 * right);
//             else if (right > left) left = right = 0;
//         }
//         left = right = 0;
//         for (int i = s.length() - 1; i >= 0; --i) {
//             if (s[i] == '(') left++;
//             else right++;
//             if (left == right) result = max(result, 2 * right);
//             else if (left > right) left = right = 0;
//         }
//         return result;
//     }
// };

int main() {
    Solution s;
    cout << s.longestValidParentheses("()(()");
}