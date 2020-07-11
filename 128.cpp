/*
    Longest Consecutive Sequence

Given an unsorted array of integers, find the length of the longest consecutive elements sequence.

Your algorithm should run in O(n) complexity.

Example:

Input: [100, 4, 200, 1, 3, 2]
Output: 4
Explanation: The longest consecutive elements sequence is [1, 2, 3, 4]. Therefore its length is 4.

*/

#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
using namespace std;

// 解法一
// class UnionSet {
// private:
//     unordered_map<int, int> parent;
//     unordered_map<int, int> count; // count[x]:以x为root的元素个数
// public:
//     int max_count;
//     UnionSet(vector<int>& nums) {
//         max_count = 0;
//         for (auto i : nums) {
//             parent[i] = i;
//             count[i] = 1;
//             max_count = 1;
//         }
//     }
//     bool exist(int x) {
//         return parent.find(x) != parent.end();
//     }
//     int find(int x) {
//         if (parent[x] == x) return x;
//         else {
//             parent[x] = find(parent[x]);
//             return parent[x];
//         }
//     }
//     void union_set(int x1, int x2) {
//         int root1 = find(x1), root2 = find(x2);
//         if (root1 != root2) {
//             parent[root1] = root2;
//             count[root2] += count[root1];
//             max_count = max(max_count, count[root2]);
//         }
//     }
// };
// class Solution {
// public:
//     int longestConsecutive(vector<int>& nums) {
//         UnionSet set(nums);
//         for (auto i : nums) {
//             if (set.exist(i - 1)) set.union_set(i, i - 1);
//             if (set.exist(i + 1)) set.union_set(i, i + 1);
//         }
//         return set.max_count;
//     }
// };

// 解法二
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> m;
        int result = 0;
        for (auto i : nums) m.insert(i);
        for (auto i : nums) {
            if (m.find(i - 1) == m.end()) {
                int j = i + 1;
                while (m.find(j) != m.end()) j++;
                result = max(result, j - i);
            }
        }
        return result;
    }
};

int main() {
    vector<int> test = {0, 0, 1, -1};
    cout << Solution().longestConsecutive(test);
}