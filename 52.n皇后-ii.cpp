/*
 * @lc app=leetcode.cn id=52 lang=cpp
 *
 * [52] N皇后 II
 */

// @lc code=start
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    int totalNQueens(int n) {
        int result = 0;
        vector<string> board(n, string(n, '.'));
        backtrack(result, 0, board);
        return result;
    }
private:
    void backtrack(int& result, int row, vector<string>& board) {
        int n = board.size();
        if (row == n) {
            result++;
            return;
        }
        for (int col = 0; col < n; ++col) {
            bool flag = false;
            for (int i = row; i >= 0; --i) {
                if (board[i][col] == 'Q') flag = true;
            }
            for (int i = 0; i <= row; ++i) {
                if (col + i < n && board[row - i][col + i] == 'Q') flag = true;
                if (col - i >= 0 && board[row - i][col - i] == 'Q') flag = true;
            }
            if (flag) continue;
            board[row][col] = 'Q';
            backtrack(result, row + 1, board);
            board[row][col] = '.';
        }
    }
};
// @lc code=end

