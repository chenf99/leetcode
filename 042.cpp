/*
Trapping Rain Water

Given n non-negative integers representing an elevation map where the width of each bar is 1, 
compute how much water it is able to trap after raining.

Example:

Input: [0,1,0,2,1,0,1,3,2,1,2,1]
Output: 6
*/

#include<iostream>
#include<stack>
#include<vector>
using namespace std;

class Solution {
public:
    int trap(vector<int>& height) {
        if (height.size() <= 2) return 0;
        int result = 0;
        int bottom = height[0];
        int top = 0;
		int rock = 0, bar_num = 0;
        for (int i = 1; i < height.size(); ++i) {
            if (bottom <= height[i]) {
                //计算水量
                int water = bottom * bar_num - rock;
                result += water;
                bottom = height[i];
                top = i;
				rock = bar_num = 0;
            }
            else {
				rock += height[i];
				bar_num++;
			}
        }
        bottom = height[height.size() - 1];
		rock = bar_num = 0;
        for (int i = height.size() - 2; i >= top; --i) {
            if (bottom <= height[i]) {
                //计算水量
                int water = bottom * bar_num - rock;
                result += water;
                bottom = height[i];
				rock = bar_num = 0;
            }
            else {
				rock += height[i];
				bar_num++;
			}
        }
        return result;
    }
    
};

int main() {
    vector<int> test = {0,1,0,2,1,0,1,3,2,1,2,1};
    Solution s;
    cout << s.trap(test);
}
