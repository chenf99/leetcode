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
#include <iostream>
#include <queue>
#include <unordered_map>
using std::vector;
using std::priority_queue;
using std::unordered_map;

class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        int intervals = 0;
        unordered_map<char, int> counts;
        for (auto t : tasks) counts[t]++;
        priority_queue<int> pq;
        for (auto count : counts) pq.push(count.second);
        int cycle = n + 1;
        int all_time = 0;
        while (!pq.empty()) {
            int time = 0;
            vector<int> tmp;
            for (int i = 0; i < cycle; ++i) {
                if (!pq.empty()) {
                    tmp.push_back(pq.top());
                    pq.pop();
                    time++;
                }
            }
            for (auto i : tmp) 
                if (--i) pq.push(i);
            all_time += !pq.empty() ? cycle : time;
        }
        return all_time;
    }
};

// int main() {
//     vector<char> tasks{'A','A','A','B','B','B'};
//     std::cout << Solution().leastInterval(tasks, 2) << std::endl;
// }