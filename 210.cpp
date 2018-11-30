/*
    Course Schedule II

There are a total of n courses you have to take, labeled from 0 to n-1.

Some courses may have prerequisites, for example to take course 0 you have to first take course 1, 
which is expressed as a pair: [0,1]

Given the total number of courses and a list of prerequisite pairs, 
return the ordering of courses you should take to finish all courses.

There may be multiple correct orders, you just need to return one of them. 
If it is impossible to finish all courses, return an empty array.

Example 1:

Input: 2, [[1,0]] 
Output: [0,1]
Explanation: There are a total of 2 courses to take. To take course 1 you should have finished   
             course 0. So the correct course order is [0,1] .
Example 2:

Input: 4, [[1,0],[2,0],[3,1],[3,2]]
Output: [0,1,2,3] or [0,2,1,3]
Explanation: There are a total of 4 courses to take. To take course 3 you should have finished both     
             courses 1 and 2. Both courses 1 and 2 should be taken after you finished course 0. 
             So one correct course order is [0,1,2,3]. Another correct ordering is [0,2,1,3] .
Note:

1.The input prerequisites is a graph represented by a list of edges, not adjacency matrices. 
2.You may assume that there are no duplicate edges in the input prerequisites.
*/

#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
#include <stack>
using namespace std;


//解法一:删除源
//判断有无环:没有源，但节点集合又不为空
/*
class Solution {
public:
    vector<int> findOrder(int numCourses, vector<pair<int, int>>& prerequisites) {
        int num = numCourses;
        unordered_map<int, int> inDegree;
        for (int i = 0; i < numCourses; ++i) inDegree[i] = 0;
        vector<int> order;
        for (int i = 0; i < prerequisites.size(); ++i) {
            inDegree[prerequisites[i].first]++;
        }
        while (num != 0) {
            bool flag = false;
            for (unordered_map<int, int>::iterator itr = inDegree.begin(); itr != inDegree.end();) {
                if (itr->second == 0) {
                    flag = true;
                    order.push_back(itr->first);
                    //删除从源出去的边
                    for (vector<pair<int, int>>::iterator it = prerequisites.begin(); it != prerequisites.end();) {
                        if (it->second == itr->first) {
                            inDegree[it->first]--;
                            it = prerequisites.erase(it);
                        }
                        else it++;
                    }
                    //删除源
                    itr = inDegree.erase(itr);
                    num--;
                }
                else itr++;
            }
            //有环
            if (flag == false) return {};
        }
        return order;
    }
};
*/
static int x = []() { ios::sync_with_stdio(false); cin.tie(NULL); return 0; }();

//解法二:通过DFS获取post值，按post值递减排序
//判断有无环:如果有一条边由已有post值的点指向有prev值、但没有post值的点，则有环
class Solution {
private:
    //邻接表
    vector<vector<int> > adjList;
    vector<bool> visited;
    vector<int> prev;
    vector<int> post;
    int clock = 1;
    bool hasCircle = false;
    vector<int> order;
    void explore(int node) {
        visited[node] = true;
        //previsit
        prev[node] = clock;
        clock++;
        for (int i = 0; i < adjList[node].size(); ++i) {
            if (visited[adjList[node][i]] == false) explore(adjList[node][i]);
            else if (post[adjList[node][i]] == 0) hasCircle = true;
        }
        //postvisit
        post[node] = clock;
        clock++;
        order.insert(order.begin(), node);
    }

public:
    vector<int> findOrder(int numCourses, vector<pair<int, int>>& prerequisites) {
        visited = vector<bool>(numCourses, false);
        prev = vector<int>(numCourses, 0);
        post = vector<int>(numCourses, 0);
        adjList = vector<vector<int>>(numCourses);
        //构建邻接表
        for (int i = 0; i < prerequisites.size(); ++i) 
            adjList[prerequisites[i].second].push_back(prerequisites[i].first);
        
        for (int i = 0; i < numCourses; ++i) {
            if (visited[i] == false) {
                explore(i);
            }
        }

        if (hasCircle == true) return {};
        else return order;
    }

};

int main() {
    vector<pair<int, int>> test = {make_pair(1, 0), make_pair(2, 0), make_pair(3, 1), make_pair(3, 2)};
    for (auto i : Solution().findOrder(4, test)) 
        cout << i << " ";
}