/*
 * @lc app=leetcode.cn id=15 lang=cpp
 *
 * [15] 三数之和
 */

// @lc code=start
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

// 解法一
// class Solution {
// public:
//     vector<vector<int>> threeSum(vector<int>& nums) {
//         vector<vector<int>> result;
//         sort(nums.begin(), nums.end());
//         unordered_map<int, int> m;
//         for (int i = 0; i < nums.size(); ++i) m[nums[i]] = i;
//         for (int i = 0; i < nums.size(); ++i) {
//             if (i > 0 && nums[i] == nums[i - 1]) continue;
//             int sum = -nums[i];
//             for (int j = i + 1; j < nums.size(); ++j) {
//                 if (j > i + 1 && nums[j] == nums[j - 1]) continue;
//                 if (m.find(sum - nums[j]) != m.end() && m[sum - nums[j]] > j) {
//                     result.push_back({nums[i], nums[j],nums[m[sum - nums[j]]]});
//                 }
//             }
//         }
//         return result;
//     }
// };

// 解法二
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size(); ++i) {
            if (i > 0 && nums[i] == nums[i - 1]) continue;
            int right = nums.size() - 1;
            for (int left = i + 1; left < right; ++left) {
                if (left > i + 1 && nums[left] == nums[left - 1]) continue;
                while (nums[i] + nums[left] + nums[right] > 0 && left < right) right--;
                if (nums[i] + nums[left] + nums[right] == 0 && left < right) {
                    result.push_back({nums[i], nums[left], nums[right]});
                }
            }
        }
        return result;
    }
};
// @lc code=end

