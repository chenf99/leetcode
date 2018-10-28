/*
Wiggle Sort II

Given an unsorted array nums, reorder it such that nums[0] < nums[1] > nums[2] < nums[3]....

Example 1:

Input: nums = [1, 5, 1, 1, 6, 4]
Output: One possible answer is [1, 4, 1, 5, 1, 6].
Example 2:

Input: nums = [1, 3, 2, 2, 3, 1]
Output: One possible answer is [2, 3, 1, 3, 1, 2].

Note:
You may assume all input has valid answer.

Follow Up:
Can you do it in O(n) time and/or in-place with O(1) extra space?

*/

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

/*
class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        //nth_element(nums.begin(), nums.begin() + nums.size() / 2, nums.end());
        int len = nums.size();
        int mid = nums[len /  2];
        int odd = 1, even = (len % 2) ? len - 1 : len - 2;
        vector<int> tmp(len, mid);
        for(int i = len - 1; i > len / 2; i--) {
            tmp[odd] = nums[i];
            odd += 2;
        }
        for(int i = 0; i < len / 2; i++) {
            tmp[even] = nums[i];
            even -= 2;
        }
        nums = tmp;
    }
};

*/

class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        nth_element(nums.begin(), nums.begin() + nums.size() / 2, nums.end());
        int len = nums.size();
        int mid = nums[len / 2];

        for (int i = 0, left = 0, right = len - 1; i <= right;) {
            if (nums[mappedIndex(i, len)] > mid) swap(nums, mappedIndex(left++, len), mappedIndex(i++, len));
            else if (nums[mappedIndex(i, len)] < mid) swap(nums, mappedIndex(right--, len), mappedIndex(i, len));
            else i++;
        }
    }

private:
    void swap(vector<int>& nums, int index1, int index2) {
        int tmp = nums[index1];
        nums[index1] = nums[index2];
        nums[index2] = tmp;
    }
    //把从0～len - 1的index映射到1, 3, 5, ..., 2, 4, 6, ...
    int mappedIndex(int index, int len) {
        return (1 + 2 * index) % (len | 1);
    }
};

int main() {
    vector<int> nums{4,5,5,5,5,6,6,6};
    Solution().wiggleSort(nums);
    //nth_element(nums.begin(), nums.begin() + nums.size() / 2, nums.end());
    for (auto i : nums) cout << i << " ";
}