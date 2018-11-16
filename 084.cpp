/*
Largest Rectangle in Histogram

Given n non-negative integers representing the histogram's bar height where the width of each bar is 1, 
find the area of largest rectangle in the histogram.

Above is a histogram where width of each bar is 1, given height = [2,1,5,6,2,3].

The largest rectangle is shown in the shaded area, which has area = 10 unit.

Example:

Input: [2,1,5,6,2,3]
Output: 10

*/

#include <iostream>
#include <vector>
#include <map>
using namespace std;

//解法一
/*
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int result = 0;
        map<int, int>area;
        for (auto i : heights) {
            //判断这个高度的矩形的面积是否被计算过
            if (area.find(i) == area.end()) {
                area.insert(std::pair<int, int>(i, calc(i, heights)));
                result = max(result, area[i]);
            }
        }
        return result;
    }
private:
    int calc(int h, const vector<int>& heights) {
        int left, right;
        left = right = -1;
        int area = 0;
        for (int i = 0; i < heights.size(); ++i) {
            //矩形左下标
            if (heights[i] >= h && left == -1) left = right = i;
            //矩形右下标右移
            else if (heights[i] >= h) right++;
            //h小于矩形高度，计算当前最大矩形面积
            else if (left != -1) {
                area = max(area, (right - left + 1) * h);
                left = right = -1;
            }
        }
        //不要遗漏右下标为最后一个下标的矩形面积
        if (right == heights.size() - 1) {
            area = max(area, (right - left + 1) * h);
        }
        return area;
    }
};
*/

//解法二
class Solution {
public:
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

int main() {
    vector<int> test = {2, 1, 5, 6, 2, 3};
    cout << Solution().largestRectangleArea(test);
}