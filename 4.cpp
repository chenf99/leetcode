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
#include <climits>
using namespace std;

// 解法一
// class Solution {
// public:
//    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
//         int m = nums1.size();
//         int n = nums2.size();
//         int mid = (m + n) / 2;
//         int index1 = 0, index2 = 0;
//         int old_tmp = 0, new_tmp = 0;;
//         while ((index1 + index2) <= mid) {
//             old_tmp = new_tmp;
//             if (index1 == m) new_tmp = nums2[index2++];
//             else if (index2 == n) new_tmp = nums1[index1++];
//             else if (nums1[index1] < nums2[index2]) new_tmp = nums1[index1++];
//             else new_tmp = nums2[index2++];
//         }
//         return (m + n) % 2 == 0 ? (old_tmp + new_tmp) / 2.0 : new_tmp;
//    }
// };

// 解法二
// class Solution {
// public:
//    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
//         int m = nums1.size();
//         int n = nums2.size();
//         if (m > n) return findMedianSortedArrays(nums2, nums1);
//         int imin = 0, imax = m;
//         int max_left = 0, min_right = 0;
//         while (imin <= imax) {
//             int i = (imin + imax) / 2;
//             int j = (m + n) / 2 - i;
//             int i_left = (i == 0 ? INT_MIN : nums1[i - 1]);
//             int j_left = (j == 0 ? INT_MIN : nums2[j - 1]);
//             int i_right = (i == m ? INT_MAX : nums1[i]);
//             int j_right = (j == n ? INT_MAX : nums2[j]);
//             if (i_left > j_right) imax = i - 1;
//             else if (j_left > i_right) imin = i + 1;
//             else {
//                 max_left = max(i_left, j_left);
//                 min_right = min(i_right, j_right);
//                 break;
//             }
//         }
//         return (m + n) % 2 == 0 ? (max_left + min_right) / 2.0 : min_right;
//    }
// };

// 解法三
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size(), n = nums2.size();
        if ((m + n) % 2 == 0) 
            return (findKElement((m + n) / 2 + 1, nums1, nums2) + findKElement((m + n) / 2, nums1, nums2)) / 2;
        else 
            return findKElement((m + n + 1) / 2, nums1, nums2);
    }
    double findKElement(int k, vector<int> nums1, vector<int> nums2){
        while (k > 1 && !nums1.empty() && !nums2.empty()) {
            int a1 = min(k / 2 - 1, (int)nums1.size() - 1);
            int a2 = min(k / 2 - 1, (int)nums2.size() - 1);
            if (nums1[a1] <= nums2[a2]) {
                nums1.erase(nums1.begin(), nums1.begin() + a1 + 1);
                k -= (a1 + 1);
            }
            else {
                nums2.erase(nums2.begin(), nums2.begin() + a2 + 1);
                k -= (a2 + 1);
            }
        }
        if (nums1.empty()) return (double)nums2[k - 1];
        if (nums2.empty()) return (double)nums1[k - 1];
        return (double)min(nums1[0], nums2[0]);
    }
};

int main() {
    Solution test;
    int a[2] = {1, 3};
    int b[1] = {2};
    vector<int> nums1(a, a + 2);
    vector<int> nums2(b, b + 1);
    
    cout << Solution().findMedianSortedArrays(nums1, nums2);
}