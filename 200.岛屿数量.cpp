/*
 * @lc app=leetcode.cn id=200 lang=cpp
 *
 * [200] 岛屿数量
 */

// @lc code=start
#include <vector>
#include <queue>
using namespace std;

// 解法一
class UnionSet {
private:
    int *parent;
    int n, m;
public:
    int count = 0;

    UnionSet(int n, int m, vector<vector<char>>& grid): n(n), m(m) {
        parent = new int[n * m];
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (grid[i][j] == '1') count++;
                parent[i * m + j] = i * m + j;
            }
        }
    }

    int find(int x) {
        if (parent[x] == x) return parent[x];
        else {
            parent[x] = find(parent[x]);
            return parent[x];
        }
    }

    void union_set(int i1, int j1, int i2, int j2) {
        int x1 = i1 * m + j1, x2 = i2 * m + j2;
        int root1 = find(x1), root2 = find(x2);
        if (parent[root1] != parent[root2]) {
            parent[root1] = root2;
            count--;
        }
    }

    ~UnionSet() {
        delete[] parent;
    }
};

class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        if (!grid.size() || !grid[0].size()) return 0;
        int n = grid.size(), m = grid[0].size();
        UnionSet set(n, m, grid);
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (grid[i][j] == '1') {
                    if (j + 1 < m && grid[i][j + 1] == '1') set.union_set(i, j, i, j + 1);
                    if (i + 1 < n && grid[i + 1][j] == '1') set.union_set(i, j, i + 1, j);
                }
            }
        }
        return set.count;
    }
};

// 解法二
class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        if (!grid.size() || !grid[0].size()) return 0;
        int n = grid.size(), m = grid[0].size();
        int count = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (grid[i][j] == '1') {
                    grid[i][j] = '0';
                    dfs(grid, i, j);
                    count++;
                }
            }
        }
        return count;
    }
private:
    void dfs(vector<vector<char>>& grid, int i, int j) {
        if (i + 1 < grid.size() && grid[i + 1][j] == '1') grid[i + 1][j] = '0', dfs(grid, i + 1, j);
        if (i - 1 >= 0 && grid[i - 1][j] == '1') grid[i - 1][j] = '0', dfs(grid, i - 1, j);
        if (j + 1 < grid[0].size() && grid[i][j + 1] == '1') grid[i][j + 1] = '0', dfs(grid, i, j + 1);
        if (j - 1 >= 0 && grid[i][j - 1] == '1') grid[i][j - 1] = '0', dfs(grid, i, j - 1);
    }
};


// 解法三
class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        if (!grid.size() || !grid[0].size()) return 0;
        int n = grid.size(), m = grid[0].size();
        int count = 0;
        queue<pair<int, int>> q;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (grid[i][j] == '1') {
                    grid[i][j] = '0';
                    q.push({i, j});
                    while (!q.empty()) {
                        auto [x, y] = q.front();
                        q.pop();
                        if (x + 1 < grid.size() && grid[x + 1][y] == '1') {
                            q.push({x + 1, y});
                            grid[x + 1][y] = '0';
                        }
                        if (x - 1 >= 0 && grid[x - 1][y] == '1') {
                            q.push({x - 1, y});
                            grid[x - 1][y] = '0';
                        }
                        if (y + 1 < grid[0].size() && grid[x][y + 1] == '1') {
                            q.push({x, y + 1});
                            grid[x][y + 1] = '0';
                        }
                        if (y - 1 >= 0 && grid[x][y - 1] == '1') {
                            q.push({x, y - 1});
                            grid[x][y - 1] = '0';
                        }
                    }
                    count++;
                }
            }
        }
        return count;
    }
};
// @lc code=end

