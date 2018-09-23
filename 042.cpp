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
        stack<int> s;
        int bottom = height[0];
        int top = 0;
        for (int i = 1; i < height.size(); ++i) {
            if (bottom <= height[i]) {
                //计算水量
                int rock = 0, bar_num = 0;
                while (!s.empty()) {
                    int tmp = s.top();
                    s.pop();
                    rock += tmp;
                    bar_num++;
                }
                int water = bottom * bar_num - rock;
                //cout << i << " " << water << " " << bar_num << endl;
                result += water;
                bottom = height[i];
                top = i;
            }
            else s.push(height[i]);
        }
        stack<int> s2;
        bottom = height[height.size() - 1];
        for (int i = height.size() - 2; i >= top; --i) {
            if (bottom <= height[i]) {
                //计算水量
                int rock = 0, bar_num = 0;
                while (!s2.empty()) {
                    int tmp = s2.top();
                    s2.pop();
                    rock += tmp;
                    bar_num++;
                }
                int water = bottom * bar_num - rock;
                //cout << i << " " << water << " " << bar_num << endl;
                result += water;
                bottom = height[i];
            }
            else s2.push(height[i]);
        }
        return result;
    }
    
};

int main() {
    vector<int> test = {0,1,0,2,1,0,1,3,2,1,2,1};
    Solution s;
    cout << s.trap(test);
}