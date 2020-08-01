/*
 * @lc app=leetcode.cn id=76 lang=cpp
 *
 * [76] 最小覆盖子串
 */

// @lc code=start
#include <string>
#include <unordered_map>
#include <climits>
using namespace std;

class Solution {
public:
    string minWindow(string s, string t) {
        int left = 0, right = 0;
        unordered_map<char, int> count_t;
        for (auto& c : t) count_t[c]++;
        unordered_map<char, int> count_w;
        int match = 0;
        int start = 0, minLen = INT_MAX;
        while (right < s.size()) {
            char c1 = s[right];
            if (count_t.count(c1)) {
                count_w[c1]++;
                if (count_w[c1] == count_t[c1]) match++;
            }
            while (match == count_t.size()) {
                if (right - left + 1 < minLen) {
                    start = left;
                    minLen = right - left + 1;
                }
                char c2 = s[left++];
                if (count_t.count(c2)) {
                    count_w[c2]--;
                    if (count_w[c2] < count_t[c2]) match--;
                }
            }
            right++;
        }
        return minLen == INT_MAX ? "" : s.substr(start, minLen);
    }
};
// @lc code=end

