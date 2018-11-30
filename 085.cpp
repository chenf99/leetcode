/*

Maximal Rectangle

Given a 2D binary matrix filled with 0's and 1's, 
find the largest rectangle containing only 1's and return its area.

Example:

Input:
[
  ["1","0","1","0","0"],
  ["1","0","1","1","1"],
  ["1","1","1","1","1"],
  ["1","0","0","1","0"]
]
Output: 6

*/

#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int maximalRectangle(vector<vector<char> >& matrix) {
        if (matrix.size() == 0) return 0;
        int result = 0;
        vector<int> heights(matrix[0].size(), 0);

        for (int i = 0; i < matrix.size(); ++i) {
            for (int j = 0; j < matrix[i].size(); ++j) {
                if (matrix[i][j] == '0') heights[j] = 0;
                else heights[j]++;
            }
            result = max(result, largestRectangleArea(heights));
        }
        return result;
    }

    int largestRectangleArea(vector<int>& heights) {
        int result = 0;
        int n = heights.size();
        if (n == 0) return 0;
        int left[n], right[n];
        left[0] = -1;
        right[n - 1] = n;
        for (int i = 1; i < n; ++i) {
            if (heights[i] > heights[i - 1]) left[i] = i - 1;
            else {
                //找第一个小于当前元素的元素下标
                int tmp = left[i - 1];
                while (heights[i] <= heights[tmp] && tmp != -1) {
                    tmp = left[tmp];
                }
                left[i] = tmp;
            }
        }
        for (int i = n - 2; i >= 0; --i) {
            if (heights[i] > heights[i + 1]) right[i] = i + 1;
            else {
                //找第一个小于当前元素的元素下标
                int tmp = right[i + 1];
                while (heights[i] <= heights[tmp] && tmp != n) {
                    tmp = right[tmp];
                }
                right[i] = tmp;
            }
            result = max(result, (right[i] - left[i] - 1) * heights[i]);
        }
        result = max(result, (right[n - 1] - left[n - 1] - 1) * heights[n - 1]);
        return result;
    }
};

static int x = []() { ios::sync_with_stdio(false); cin.tie(NULL); return 0; }();

int main() {
    vector<vector<char> > test(4, vector<char>(5));
    char arr[4][5] = {
        {1, 0, 1, 0, 1}, 
        {1, 0, 1, 1, 1}, 
        {1, 1, 1, 1, 1}, 
        {1, 0, 0, 1, 0}
    };
    for (int i = 0; i < 4; ++i)
        for (int j = 0; j < 5; ++j) 
        test[i][j] = arr[i][j];
    cout << Solution().maximalRectangle(test);
}