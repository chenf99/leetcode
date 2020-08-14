/*
 * @lc app=leetcode.cn id=739 lang=cpp
 *
 * [739] 每日温度
 */

// @lc code=start
#include <vector>
#include <stack>
using std::vector;
using std::stack;

// 解法一
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& T) {
        int n = T.size();
        vector<int> ans(n, 0);
        for (int i = n - 2; i >= 0; --i) {
            int index = i + 1;
            while (index < n) {
                if (T[i] < T[index]) {
                    ans[i] = index - i;
                    break;
                }
                else if (ans[index] != 0) index += ans[index];
                else break;
            }
        }
        return ans;
    }
};

// 解法二
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& T) {
        int n = T.size();
        vector<int> ans(n, 0);
        stack<int> stk;
        stk.push(0);
        for (int i = 1; i < n; ++i) {
            int num = stk.top();
            if (T[num] < T[i]) {
                while (!stk.empty() && T[stk.top()] < T[i]) {
                    num = stk.top();
                    ans[num] = i - num;
                    stk.pop();
                }
            }
            stk.push(i);
        }
        return ans;
    }
};
// @lc code=end

