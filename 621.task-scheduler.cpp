/*
 * @lc app=leetcode id=621 lang=cpp
 *
 * [621] Task Scheduler
 *
 * https://leetcode.com/problems/task-scheduler/description/
 *
 * algorithms
 * Medium (44.69%)
 * Total Accepted:    92.3K
 * Total Submissions: 201.3K
 * Testcase Example:  '['A','A','A','B','B','B']\n2'
 *
 * Given a char array representing tasks CPU need to do. It contains capital
 * letters A to Z where different letters represent different tasks. Tasks
 * could be done without original order. Each task could be done in one
 * interval. For each interval, CPU could finish one task or just be idle.
 * 
 * However, there is a non-negative cooling interval n that means between two
 * same tasks, there must be at least n intervals that CPU are doing different
 * tasks or just be idle.
 * 
 * You need to return the least number of intervals the CPU will take to finish
 * all the given tasks.
 * 
 * 
 * 
 * Example:
 * 
 * 
 * Input: tasks = ['A','A','A','B','B','B'], n = 2
 * Output: 8
 * Explanation: A -> B -> idle -> A -> B -> idle -> A -> B.
 * 
 * 
 * 
 * 
 * Note:
 * 
 * 
 * The number of tasks is in the range [1, 10000].
 * The integer n is in the range [0, 100].
 * 
 * 
 */
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

// 解法一
class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        int hash[26] = {0};
        for (auto c : tasks) hash[c - 'A']++;
        int num = 0;
        for (int i = 0; i < 26; ++i) num += hash[i] > 0;
        int count = 0;
        while (num) {
            sort(hash, hash + 26, [](int& a, int& b) { return a > b;});
            int i = 0;
            while (i <= n && hash[i] > 0) {
                if (--hash[i] == 0) num--;
                i++;
            }
            if (num == 0) count += i;
            else count += n + 1;
        }
        return count;
    }
};

// 解法二
class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        int hash[26] = {0};
        for (auto c : tasks) hash[c - 'A']++;
        priority_queue<int> pq;
        for (int i = 0; i < 26; ++i) if (hash[i] > 0) pq.push(hash[i]);
        int count = 0;
        while (!pq.empty()) {
            int i = 0;
            vector<int> tmp;
            while (i <= n && !pq.empty()) {
                int num = pq.top();
                pq.pop();
                if (--num > 0) tmp.push_back(num);
                i++;
            }
            for (auto num : tmp) pq.push(num);
            count += pq.empty() ? i : n + 1;
        }
        return count;
    }
};

// 解法三
class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        int hash[26] = {0};
        for (auto c : tasks) hash[c - 'A']++;
        int count = 0;
        sort(hash, hash + 26);
        int max = hash[25];
        int occupied = max, idle = (max - 1) * n;
        for (int i = 24; i >= 0; --i) {
            if (hash[i]) {
                if (hash[i] > idle) return tasks.size();
                occupied += hash[i];
                if (hash[i] <= max - 1) idle -= hash[i];
                else idle -= hash[i] - 1;
            }
        }
        return occupied + idle;
    }
};

// 解法四（解法三的优化）
class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        int hash[26] = {0};
        for (auto c : tasks) hash[c - 'A']++;
        int count = 0;
        sort(hash, hash + 26, greater<int>());
        int i = 1;
        while (i < 26 && hash[i] == hash[0]) i++;
        return max((int)tasks.size(), i + (hash[0] - 1) * (n + 1));
    }
};