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

// 遍历图
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

// 并查集
class Solution {
public:
    unordered_map<string, string> parents; // a->parents[a]
    unordered_map<string, double> weights; // weights[a]: a / parents[a]

    pair<string, double> MyFind(string& x) {
        if (!parents.count(x)) return {"", -1.0};
        double weight = 1.0;
        while (x != parents[x]) {
            weight *= weights[x];
            x = parents[x];
        }
        return {x, weight}; //x最终为root, weight代表x / root的值
    }

    void MyUnion(string& a, string& b, double value) {
        pair<string, double> root1 = MyFind(a);
        pair<string, double> root2 = MyFind(b);
        if (root1.first == root2.first) return;
        parents[root1.first] = root2.first;
        // root1.second: a / root1, value: a / b, root2.second: b / root2
        weights[root1.first] = 1.0 / root1.second * value * root2.second;
    }

    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        int n = equations.size();
        for (int i = 0; i < n; ++i) {
            string x = equations[i][0], y = equations[i][1];
            if (!parents.count(x)) parents[x] = x, weights[x] = 1.0;
            if (!parents.count(y)) parents[y] = y, weights[y] = 1.0;
            MyUnion(x, y, values[i]);
        }
        vector<double> ans;
        for (auto& query : queries) {
            string x = query[0], y = query[1];
            pair<string, double> root1 = MyFind(x);
            pair<string, double> root2 = MyFind(y);
            if (root1.first != root2.first || root1.first == "" || root2.first == "") ans.push_back(-1.0);
            else ans.push_back(root1.second / root2.second);
        }
        return ans;
    }
};
// @lc code=end