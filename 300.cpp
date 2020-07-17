/*
Longest Increasing Subsequence

Given an unsorted array of integers, find the length of longest increasing subsequence.

Example:

Input: [10,9,2,5,3,7,101,18]
Output: 4 
Explanation: The longest increasing subsequence is [2,3,7,101], therefore the length is 4. 
Note:

There may be more than one LIS combination, it is only necessary for you to return the length.
Your algorithm should run in O(n2) complexity.
Follow up: Could you improve it to O(n log n) time complexity?
*/

#include <iostream>
#include <vector>
#include <climits>
using namespace std;

//解法一
/*
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int dp[nums.size()]; // dp[i]:以第i个数字为结尾的最长上升子序列长度
        int result = 0;
        for (int i = 0; i < nums.size(); ++i) {
            int max_dp = 0;
            for (int j = 0; j < i; ++j) {
                if (nums[j] < nums[i] && dp[j] > max_dp) max_dp = dp[j];
            }
            dp[i] = max_dp + 1;
            result = max(result, dp[i]);
        }
        return result;
    }
};
*/

//解法二
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        if (nums.size() == 0) return 0;
        int dp[nums.size() + 1]; // dp[i]: 长度为i的最长上升子序列的最末元素的最小值
        int len = 1;
        dp[1] = nums[0];
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] > dp[len]) dp[++len] = nums[i];
            else {
                int left = 1, right = len;
                while (left <= right) {
                    int mid = (left + right) / 2;
                    if (dp[mid] >= nums[i]) right = mid - 1;
                    else left = mid + 1;
                }
                dp[left] = nums[i];
            }
        }
        return len;
    }
};

int main() {
    vector<int> test = {4, 10, 4, 3, 8, 9};
    cout << Solution().lengthOfLIS(test) << endl;
}