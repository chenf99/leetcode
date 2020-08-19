/*
 * @lc app=leetcode.cn id=347 lang=cpp
 *
 * [347] 前 K 个高频元素
 */

// @lc code=start
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <queue>
using namespace std;

// 解法一
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> ans;
        unordered_map<int, int> mp;
        for (auto num : nums) mp[num]++;
        vector<pair<int, int>> tmp;
        for (auto i : mp) tmp.push_back(i);
        sort(tmp.begin(), tmp.end(), [] (pair<int, int>& a, pair<int, int>& b) { return a.second > b.second;});
        for (int i = 0; i < k; ++i) ans.push_back(tmp[i].first);
        return ans;
    }
};

// 解法二 桶排序
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> ans;
        unordered_map<int, int> mp;
        for (auto num : nums) mp[num]++;
        vector<vector<int>> bucket(nums.size() + 1);
        // 频率作为桶的下标
        for (auto i : mp) bucket[i.second].push_back(i.first);
        for (int i = nums.size(); i >= 0; --i) {
            if (bucket[i].size() == 0) continue;
            for (auto value : bucket[i]) ans.push_back(value);
            if (ans.size() == k) break;
        }
        return ans;
    }
};

// 解法三 堆排序
class Solution {
public:
    struct cmp{
        bool operator() (pair<int, int> a, pair<int, int> b) {
            return a.second < b.second;
        }
    };

    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> ans;
        unordered_map<int, int> mp;
        for (auto num : nums) mp[num]++;
        priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> q;
        for (auto i : mp) q.push({i.first, i.second});
        for (int i = 0; i < k; ++i) {
            ans.push_back(q.top().first);
            q.pop();
        }
        return ans;
    }
};
// @lc code=end

