/*
 * @lc app=leetcode.cn id=438 lang=cpp
 *
 * [438] 找到字符串中所有字母异位词
 */

// @lc code=start
#include <vector>
#include <string>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> result = {};
        unordered_map<char, int> count_p;
        for (auto c : p) count_p[c]++;
        unordered_map<char, int> count_w;
        int match = 0;
        int left = 0, right = 0;
        while (right < s.size()) {
            char c1 = s[right++];
            count_w[c1]++;
            if (count_p.count(c1) && count_w[c1] == count_p[c1]) match++;
            if (right - left == p.size()) {
                if (match == count_p.size()) result.emplace_back(left);
                char c2 = s[left++];
                count_w[c2]--;
                if (count_p.count(c2) && count_w[c2] == count_p[c2] - 1) match--;
            }
        }
        return result;
    }
};
// @lc code=end

