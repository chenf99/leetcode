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
        if (nums.size() == 0) return 0;
        //L[i]表示以第i个数结尾的最长递增子序列的长度
        int n = nums.size();
        int L[n];
        int max_L;//max_L表示结果
        L[0] = max_L = 1;
        for (int i = 1; i < n; ++i) {
            int tmp = 0;//tmp表示与结点i相连的上一个结点的最大L值
            for (int j = 0; j < i; ++j) {
                if (nums[j] < nums[i] && tmp < L[j]) tmp = L[j];
            }
            L[i] = 1 + tmp;
            if (max_L < L[i]) max_L = L[i];
        }
        return max_L;
    }
};
*/

//解法二
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        if (nums.size() == 0) return 0;
        //d[k]表示长度为k的子序列的最末元素，
        //如果有多个这种元素，取最小的那个
        //注意d[k]是递增序列
        int n = nums.size();
        int d[n + 1], len;//len表示当前最长子序列的长度
        len = 1;
        d[1] = nums[0];
        for (int i = 1; i < n; ++i) {
            if (nums[i] > d[len]) d[++len] = nums[i];
            else {
                //用二分法查找大于等于nums[i]的第一个d[j]
                int left = 1, right = len;
                while (left <= right) {
                    int mid = (left + right) / 2;
                    if (d[mid] >= nums[i]) right = mid - 1;
                    else left = mid + 1;
                }
                d[left] = nums[i];
            }
        }
        return len;
    }
};

int main() {
    vector<int> test = {4, 10, 4, 3, 8, 9};
    cout << Solution().lengthOfLIS(test) << endl;
}