/*
 * @lc app=leetcode.cn id=48 lang=cpp
 *
 * [48] 旋转图像
 */

// @lc code=start
#include <vector>
using namespace std;

// 解法一
// class Solution {
// public:
//     void rotate(vector<vector<int>>& matrix) {
//         int n = matrix.size();
//         for (int i = 0; i < n; ++i) {
//             for (int j = i + 1; j < n; ++j) {
//                 int tmp = matrix[i][j];
//                 matrix[i][j] = matrix[j][i];
//                 matrix[j][i] = tmp;
//             }
//         }
//         for (int j = 0; j < n / 2; ++j) {
//             for (int i = 0; i < n; ++i) {
//                 int tmp = matrix[i][j];
//                 matrix[i][j] = matrix[i][n - 1 - j];
//                 matrix[i][n - 1 - j] = tmp;
//             }
//         }
//     }
// };

// 解法二
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        // 一次性旋转4个元素，通过3次交换来实现
        for (int i = 0; i < n / 2; ++i) {
            for (int j = i; j < n - 1 - i; ++j) {
                swap(matrix[i][j], matrix[j][n - 1 - i]);
                swap(matrix[i][j], matrix[n - 1 - j][i]);
                swap(matrix[n - 1 - j][i], matrix[n - 1 - i][n - 1 - j]);
            }
        }
    }
private:
    void swap(int& num1, int& num2) {
        int tmp = num1;
        num1 = num2;
        num2 = tmp;
    }
};
// @lc code=end

