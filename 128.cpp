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
using std::cout;
using std::vector;
using std::unordered_map;


class UnionFindSet {
private:
    int size;
    vector<int> parent;
    //child表示根节点的孩子数
    vector<int> child;
public:
    UnionFindSet(int size) {
        this->size = size;
        parent = vector<int>(size);
        child = vector<int>(size);
    }

    void makeSet() {
        for (int i = 0; i < size; ++i) {
            parent[i] = i;
            child[i] = 1;
        }
    }

    int find(int x) {
        //查找过程中使用路径压缩
        if (x != parent[x]) parent[x] = find(parent[x]);
        return parent[x];
    }

    void Union(int x, int y) {
        int parent_x = find(x);
        int parent_y = find(y);
        if (parent_x == parent_y) return;
        if (child[parent_x] > child[parent_y]) {
            parent[parent_y] = parent_x;
            child[parent_x] += child[parent_y];
        }
        else {
            parent[parent_x] = parent_y;
            child[parent_y] += child[parent_x];
        }
    }

    int max_child() {
        int max = 1;
        for (auto i : child) {
            if (max < i) max = i;
        }
        return max;
    }
};

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if (nums.size() == 0) return 0;
        //利用hashmap来记录元素是否存在
        //键为元素值，值为元素在并查集中的位置
        unordered_map<int, int> map;
        for (int i = 0; i < nums.size(); ++i) {
            map.insert(std::make_pair(nums[i], i));
        }
        UnionFindSet set(nums.size());
        set.makeSet();
        for (auto it = map.begin(); it != map.end(); ++it) {
            auto smaller = map.find(it->first - 1);
            auto bigger = map.find(it->first + 1);
            //比元素小1的元素存在
            if (smaller != map.end()) {
                set.Union(it->second, map[it->first - 1]);
            }
            //比元素小1的元素存在
            if (bigger != map.end()) {
                set.Union(it->second, map[it->first + 1]);
            }
        }
        return set.max_child();
    }
};

int main() {
    vector<int> test = {0, 0, 1, -1};
    cout << Solution().longestConsecutive(test);
}