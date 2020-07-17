/*
Next Permutation

Implement next permutation, which rearranges numbers into 
the lexicographically next greater permutation of numbers.

If such arrangement is not possible, it must rearrange it as 
the lowest possible order (ie, sorted in ascending order).

The replacement must be in-place and use only constant extra memory.

Here are some examples. Inputs are in the left-hand column and 
its corresponding outputs are in the right-hand column.

1,2,3 → 1,3,2
3,2,1 → 1,2,3
1,1,5 → 1,5,1
*/

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int len = nums.size();
        if (len == 1) return;
        bool flag = false;  //是否存在下一个置换
        int index;
        for (index = len - 1; index > 0; --index) {
            if (nums[index] > nums[index - 1]) {
                flag = true;
                break;
            }
        }
        if (flag == false) return reverse(nums.begin(), nums.end());//没有下一个置换
        reverse(nums.begin() + index, nums.end());
        int small_index = -1;
        for (int i = index; i < len; ++i) {
            if (nums[i] > nums[index - 1]) {
                if (small_index == -1) small_index = i;
                else if (nums[i] < nums[small_index]) small_index = i;
            }
        }
        int temp = nums[small_index];
        nums[small_index] = nums[index - 1];
        nums[index - 1] = temp;
    }
};

int main() {
    vector<int> test = {2, 3, 1, 3, 3};
    Solution().nextPermutation(test);
}