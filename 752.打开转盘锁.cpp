/*
 * @lc app=leetcode.cn id=752 lang=cpp
 *
 * [752] 打开转盘锁
 */

// @lc code=start
#include <vector>
#include <string>
#include <queue>
#include <unordered_set>
using namespace std;

class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        unordered_set<string> dead_set;
        for (auto dead : deadends) dead_set.insert(dead);
        unordered_set<string> visited;
        int step = 0;
        string start = "0000";
        queue<string> q;
        q.push(start);
        visited.insert(start);
        while (!q.empty()) {
            int n = q.size();
            for (int i = 0; i < n; ++i) {
                string curr = q.front();
                q.pop();
                if (curr == target) return step;
                if (dead_set.count(curr)) continue;
                for (int i = 0; i < 4; ++i) {
                    char tmp = curr[i];
                    if (tmp == '9') curr[i] = '0';
                    else curr[i] += 1;
                    if (!visited.count(curr)) {
                        q.push(curr);
                        visited.insert(curr);
                    }
                    curr[i] = tmp;
                    if (tmp == '0') curr[i] = '9';
                    else curr[i] -= 1;
                    if (!visited.count(curr)) {
                        q.push(curr);
                        visited.insert(curr);
                    }
                    curr[i] = tmp;
                }
            }
            step++;
        }
        return -1;
    }
};
// @lc code=end

