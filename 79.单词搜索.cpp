/*
 * @lc app=leetcode.cn id=79 lang=cpp
 *
 * [79] 单词搜索
 */

// @lc code=start
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size(), n = board[0].size();
        vector<vector<bool>> used(m, vector<bool>(n, false));
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (board[i][j] == word[0]) {
                    used[i][j] = true;
                    if (dfs(board, word, i, j, 1, used)) return true;
                    used[i][j] = false;
                }
            }
        }
        return false;
    }
private:
    int directions[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    bool dfs(vector<vector<char>>& board, string& word, int i, int j, int index, vector<vector<bool>>& used) {
        if (index == word.size()) {
            return true;
        }
        for (auto& pair : directions) {
            int x = i + pair[0], y = j + pair[1];
            if (x >= 0 && x < board.size() && y >= 0 && y < board[0].size()) {
                if (!used[x][y] && board[x][y] == word[index]) {
                    used[x][y] = true;
                    if (dfs(board, word, x, y, index + 1, used)) return true;
                    used[x][y] = false;
                }
            }
        }
        return false;
    }
};
// @lc code=end

