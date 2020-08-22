/*
 * @lc app=leetcode.cn id=399 lang=cpp
 *
 * [399] 除法求值
 */

// @lc code=start
#include <vector>
#include <string>
#include <unordered_map>
#include <queue>
using namespace std;

class Solution {
public:
    struct edge {
        string node;
        double weight;
        edge (string node, double weight): node(node), weight(weight) {}
    };
    
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        unordered_map<string, vector<edge>> edges;
        int n = equations.size();
        // 构造无向带权图
        for (int i = 0; i < n; ++i) {
            string x = equations[i][0], y = equations[i][1];
            edges[x].push_back(edge(y, values[i]));
            edges[y].push_back(edge(x, 1 / values[i]));
        }
        vector<double> ans;
        for (auto& query : queries) {
            string x = query[0], y = query[1];
            bool flag = false;
            // 图里是否存在从x到y的一条路径
            unordered_map<string, int> used;
            queue<pair<string, double>> q;
            if (edges.count(x)) {
                q.push({x, 1.0});
                used[x] = 1;
            }
            while (!q.empty()) {
                auto [node, weight] = q.front();
                q.pop();
                if (node == y) {
                    ans.push_back(weight);
                    flag = true;
                    break;
                }
                for (edge& e : edges[node]) {
                    if (used[e.node] == 0) {
                        q.push({e.node, weight * e.weight});
                        used[e.node] = 1;
                    }
                }
            }
            // 不存在则query无解
            if (!flag) ans.push_back(-1.0);
        }
        return ans;
    }
};
// @lc code=end