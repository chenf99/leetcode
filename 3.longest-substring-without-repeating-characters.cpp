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
#include <algorithm>
#include <iostream>
using std::string;
using std::max;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        string curr = "";
        int max_len = 0;
        for (int i = 0; i < s.length(); ++i) {
            if (curr.find(s[i]) == string::npos) {
                curr += s[i];
            }
            else {
                max_len = max(max_len, (int)curr.length());
                curr = curr.substr(curr.find(s[i]) + 1) + s[i];
            }
        }
        max_len = max(max_len, (int)curr.length());
        return max_len;
    }
};

// int main() {
//     std::cout << Solution().lengthOfLongestSubstring("pwwekw") << std::endl;
// }