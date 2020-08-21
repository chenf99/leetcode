/*
 * @lc app=leetcode.cn id=394 lang=cpp
 *
 * [394] 字符串解码
 */

// @lc code=start
#include <string>
#include <stack>
using std::string;
using std::stack;

class Solution {
public:
    string decodeString(string s) {
        stack<char> stk;
        string ans = "";
        int num = 0;
        for (int i = 0; i < s.size(); ) {
            if (s[i] >= '0' && s[i] <= '9') num = num * 10 + s[i++] - '0';
            else if (s[i] == '['){
                stk.push(s[i]);
                int start = ++i;
                while (i < s.size() && !stk.empty()) {
                    if (s[i] == '[') stk.push('[');
                    else if (s[i] == ']') stk.pop();
                    i++;
                }
                string str = decodeString(s.substr(start, i - 1 - start));
                for (int j = 0; j < num; ++j) ans += str;
                num = 0;
            }
            else ans += s[i++];
        }
        return ans;
    }
};
// @lc code=end

