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
        if (nums.size() <= 1) return;
        int index = nums.size() - 1;
        while (index >= 1 && nums[index] <= nums[index - 1]) index--;
        if (index == 0) reverse(nums.begin(), nums.end());
        else {
            reverse(nums.begin() + index, nums.end());
            for (int i = index; i < nums.size(); ++i) {
                if (nums[i] > nums[index - 1]) {
                    int tmp = nums[index - 1];
                    nums[index - 1] = nums[i];
                    nums[i] = tmp;
                    break;
                }
            }
        }
    }
};

int main() {
    vector<int> test = {2, 3, 1, 3, 3};
    Solution().nextPermutation(test);
}