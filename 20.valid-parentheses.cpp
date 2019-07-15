/*
 * @lc app=leetcode id=20 lang=cpp
 *
 * [20] Valid Parentheses
 *
 * https://leetcode.com/problems/valid-parentheses/description/
 *
 * algorithms
 * Easy (36.05%)
 * Total Accepted:    632.4K
 * Total Submissions: 1.7M
 * Testcase Example:  '"()"'
 *
 * Given a string containing just the characters '(', ')', '{', '}', '[' and
 * ']', determine if the input string is valid.
 * 
 * An input string is valid if:
 * 
 * 
 * Open brackets must be closed by the same type of brackets.
 * Open brackets must be closed in the correct order.
 * 
 * 
 * Note that an empty string is also considered valid.
 * 
 * Example 1:
 * 
 * 
 * Input: "()"
 * Output: true
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: "()[]{}"
 * Output: true
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: "(]"
 * Output: false
 * 
 * 
 * Example 4:
 * 
 * 
 * Input: "([)]"
 * Output: false
 * 
 * 
 * Example 5:
 * 
 * 
 * Input: "{[]}"
 * Output: true
 * 
 * 
 */
#include <string>
#include <stack>
#include <iostream>
using std::stack;
using std::string;

class Solution {
public:
    bool isValid(string str) {
        stack<char> s;
        for (int i = 0; i < str.length(); ++i) {
            if (s.empty()) {
                s.push(str[i]);
                continue;
            }
            if (s.top() == '(' && str[i] == ')') s.pop();
            else if (s.top() == '[' && str[i] == ']') s.pop();
            else if (s.top() == '{' && str[i] == '}') s.pop();
            else s.push(str[i]);
        }
        return s.empty();
    }
};

// int main() {
//     std::cout << Solution().isValid("[([])]");
// }