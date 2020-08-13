/*
 * @lc app=leetcode.cn id=238 lang=cpp
 *
 * [238] 除自身以外数组的乘积
 */

// @lc code=start
#include <vector>
using namespace std;

// 解法一
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size(); // n > 1
        int pre[n], post[n];
        pre[0] = post[n - 1] = 1;
        for (int i = 1; i < n; ++i) {
            pre[i] = pre[i - 1] * nums[i - 1];
        }
        for (int i = n - 2; i >= 0; --i) {
            post[i] = post[i + 1] * nums[i + 1];
        }
        vector<int> product(n);
        for (int i = 0; i < n; ++i) product[i] = pre[i] * post[i];
        return product;
    }
};

// 解法二
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size(); // n > 1
        vector<int> product(n);
        product[0] = 1;
        for (int i = 1; i < n; ++i) {
            product[i] = product[i - 1] * nums[i - 1];
        }
        int post = 1;
        for (int i = n - 1; i >= 0; --i) {
            product[i] = product[i] * post;
            post = post * nums[i];
        }
        return product;
    }
};

// 解法三
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size(); // n > 1
        vector<int> product(n, 1);
        int pre = 1, post = 1;
        for (int i = 0; i < n; ++i) {
            product[i] *= pre;
            pre *= nums[i];

            product[n - 1 - i] *= post;
            post *= nums[n - 1 - i];
        }
        return product;
    }
};
// @lc code=end

