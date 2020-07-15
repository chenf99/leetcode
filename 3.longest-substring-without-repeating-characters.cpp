/*
 * @lc app=leetcode id=3 lang=cpp
 *
 * [3] Longest Substring Without Repeating Characters
 *
 * https://leetcode.com/problems/longest-substring-without-repeating-characters/description/
 *
 * algorithms
 * Medium (28.07%)
 * Total Accepted:    992.7K
 * Total Submissions: 3.5M
 * Testcase Example:  '"abcabcbb"'
 *
 * Given a string, find the length of the longest substring without repeating
 * characters.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: "abcabcbb"
 * Output: 3 
 * Explanation: The answer is "abc", with the length of 3. 
 * 
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: "bbbbb"
 * Output: 1
 * Explanation: The answer is "b", with the length of 1.
 * 
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: "pwwkew"
 * Output: 3
 * Explanation: The answer is "wke", with the length of 3. 
 * ⁠            Note that the answer must be a substring, "pwke" is a
 * subsequence and not a substring.
 * 
 * 
 * 
 * 
 * 
 */
#include <string>
#include <iostream>
using std::string;
using std::max;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if (s.length() <= 1) return s.length();
        int start = 0, result = 1;
        for (int i = 1; i < s.length(); ++i) {
            bool flag = false;
            for (int j = start; j < i; ++j) {
                if (s[j] == s[i]) {
                    start = j + 1;
                    flag = true;
                    break;
                }
            }
            if (!flag) result = max(result, i - start + 1);
        }
        return result;
    }
};

// int main() {
//     std::cout << Solution().lengthOfLongestSubstring("pwwekw") << std::endl;
// }