/*
 * @lc app=leetcode.cn id=207 lang=cpp
 *
 * [207] 课程表
 */

// @lc code=start
#include <vector>
#include <queue>
using namespace std;

// 解法一
class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> in_degree(numCourses, 0);
        // 初始化, 定义每个节点的邻接表, 计算入度
        vector<vector<int>> edges(numCourses, vector<int>());
        for (auto i : prerequisites) {
            int u = i[0], v = i[1];
            in_degree[v]++;
            edges[u].push_back(v);
        }
        queue<int> q;
        for (int i = 0; i < numCourses; ++i) if (in_degree[i] == 0) q.push(i);
        int count = 0;
        while (!q.empty()) {
            count++;
            // 每次删除一个入度为0的节点
            int u = q.front();
            q.pop();
            // 删除它相关的边表现为入度减1
            for (int i = 0; i < edges[u].size(); ++i) {
                int v = edges[u][i];
                if (--in_degree[v] == 0) q.push(v);
            }
        }
        // 最终入度为0的节点数等于总结点数，则无环
        return count == numCourses;
    }
};

// 解法二
class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> edges(numCourses, vector<int>());
        for (auto i : prerequisites) {
            int u = i[0], v = i[1];
            edges[u].push_back(v);
        }
        vector<int> visited(numCourses, 0);
        // 0 表示未搜索, 1表示搜索中, 2表示搜索完成
        for (int i = 0; i < numCourses; ++i) {
            if (visited[i] == 0) visited[i] = 1, dfs(i, edges, visited);
        }
        return acyclic;
    }
private:
    bool acyclic = true;
    void dfs(int u, vector<vector<int>>& edges, vector<int>& visited) {
        for (int i = 0; i < edges[u].size(); ++i) {
            int v = edges[u][i];
            if (visited[v] == 1) {
                acyclic = false;
                return;
            }
            else if (visited[v] == 0) visited[v] = 1, dfs(v, edges, visited);
        }
        visited[u] = 2;
    }
};

// @lc code=end

