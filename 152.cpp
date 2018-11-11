/*
Maximum Product Subarray

Given an integer array nums, find the contiguous subarray within an array 
(containing at least one number) which has the largest product.

Example 1:

Input: [2,3,-2,4]
Output: 6
Explanation: [2,3] has the largest product 6.
Example 2:

Input: [-2,0,-1]
Output: 0
Explanation: The result cannot be 2, because [-2,-1] is not a subarray.

*/

#include<iostream>
#include<vector>
using namespace std;

//解法一
/*
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        int min[n], max[n];
        min[0] = max[0] = nums[0];
        //min[i],max[i]分别表示以第i个数结尾的子序列的最小/最大值
        for (int i = 1; i < n; ++i) {
            min[i] = std::min(std::min(min[i - 1] * nums[i], nums[i]), max[i - 1] * nums[i]);
            max[i] = std::max(std::max(max[i - 1] * nums[i], nums[i]), min[i - 1] * nums[i]);
        }
        int result = max[0];
        for (int i = 1; i < n; ++i) 
            if (result < max[i]) result = max[i];
        return result;
    }
};
*/

//解法二优化空间
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        int result;
        int min, max;
        result = min = max = nums[0];
        //min,max分别表示以第i个数结尾的子序列的最小/最大值
        for (int i = 1; i < n; ++i) {
            int tmp = min;
            min = std::min(std::min(min * nums[i], nums[i]), max * nums[i]);
            max = std::max(std::max(max * nums[i], nums[i]), tmp * nums[i]);
            if (result < max) result = max;
        }
        return result;
    }
};

int main() {
    vector<int> test = {-2, 3, 4};
    cout << Solution().maxProduct(test);
}