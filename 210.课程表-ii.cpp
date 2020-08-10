/*
 * @lc app=leetcode.cn id=210 lang=cpp
 *
 * [210] 课程表 II
 */

// @lc code=start
#include <vector>
#include <queue>
using namespace std;

// 解法一
class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> in_degree(numCourses, 0);
        vector<vector<int>> edges(numCourses, vector<int>());
        for (int i = 0; i < prerequisites.size(); ++i) {
            int v = prerequisites[i][0], u = prerequisites[i][1];
            edges[u].push_back(v);
            in_degree[v]++;
        }
        queue<int> q;
        vector<int> order;
        for (int i = 0; i < numCourses; ++i) if (in_degree[i] == 0) q.push(i);
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            order.push_back(u);
            for (int i = 0; i < edges[u].size(); ++i) {
                int v = edges[u][i];
                if (--in_degree[v] == 0) q.push(v);
            }
        }
        return order.size() == numCourses ? order : vector<int>();
    }
};

// 解法二
class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> in_degree(numCourses, 0);
        vector<vector<int>> edges(numCourses, vector<int>());
        for (int i = 0; i < prerequisites.size(); ++i) {
            int u = prerequisites[i][0], v = prerequisites[i][1];
            edges[u].push_back(v);
            in_degree[v]++;
        }
        vector<int> visited(numCourses, 0);
        vector<int> order;
        for (int i = 0; i < numCourses; ++i) {
            if (visited[i] == 0) visited[i] = 1, dfs(i, visited, edges, order);
        }
        return acyclic ? order : vector<int>();
    }
private:
    bool acyclic = true;
    void dfs(int u, vector<int>& visited, vector<vector<int>>& edges, vector<int>& order) {
        for (int i = 0; i < edges[u].size(); ++i) {
            int v = edges[u][i];
            if (visited[v] == 1) {
                acyclic = false;
                return;
            }
            else if (visited[v] == 0) visited[v] = 1, dfs(v, visited, edges, order);
        }
        visited[u] = 2;
        order.push_back(u);
    }
};
// @lc code=end

