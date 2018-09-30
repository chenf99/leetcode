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
using namespace std;

class Solution {
public:
    int longestValidParentheses(string str) {
        int result = 0, start = 0;
        stack<int> s;
        for (int i = 0; i < str.size(); ++i) {
            if (str[i] == '(') s.push(i);
            else {
                if (s.empty()) start = i + 1;
                else {
                    s.pop();
                    if (s.empty()) result = max(result, i - start + 1);
                    else result = max(result, i - s.top());
                }
            }
        }
        return result;
    }
};

int main() {
    Solution s;
    cout << s.longestValidParentheses("()(()");
}