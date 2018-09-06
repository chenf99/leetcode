/*

Median of Two Sorted Arrays

There are two sorted arrays nums1 and nums2 of size m and n respectively.
Find the median of the two sorted arrays. The overall run time complexity should be O(log (m+n)).
You may assume nums1 and nums2 cannot be both empty.

Example 1:

nums1 = [1, 3]
nums2 = [2]

The median is 2.0

Example 2:

nums1 = [1, 2]
nums2 = [3, 4]

The median is (2 + 3)/2 = 2.5
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size();
        int n = nums2.size();
        if (m == 0) return n % 2 == 0 ? (nums2[n/2 - 1] + nums2[n/2]) / 2.0 : nums2[n/2];
        else if (n == 0) return m % 2 == 0 ? (nums1[m/2 - 1] + nums1[m/2]) / 2.0 : nums1[m/2];
        int mid = (m + n) / 2;
        vector<int> sortedArr;
        for (int i = 0, j = 0; i + j <= mid; ) {
            if (i == m) sortedArr.push_back(nums2[j++]);
            else if (j == n) sortedArr.push_back(nums1[i++]);
            else if (nums1[i] <= nums2[j]) sortedArr.push_back(nums1[i++]);
            else sortedArr.push_back(nums2[j++]);
        }
        return (m + n) % 2 == 0 ? (sortedArr[mid - 1] + sortedArr[mid]) / 2.0 : sortedArr[mid];
    }
};

int main() {
    Solution test;
    int a[2] = {2, 2};
    int b[2] = {1, 1};
    vector<int> nums1(a, a + 2);
    vector<int> nums2(b, b + 2);
    
    cout << Solution().findMedianSortedArrays(nums1, nums2);
}