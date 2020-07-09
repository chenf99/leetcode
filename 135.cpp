/*
Candy

There are N children standing in a line. Each child is assigned a rating value.

You are giving candies to these children subjected to the following requirements:

Each child must have at least one candy.
Children with a higher rating get more candies than their neighbors.
What is the minimum candies you must give?

Example 1:

Input: [1,0,2]
Output: 5
Explanation: You can allocate to the first, second and third child with 2, 1, 2 candies respectively.
Example 2:

Input: [1,2,2]
Output: 4
Explanation: You can allocate to the first, second and third child with 1, 2, 1 candies respectively.
             The third child gets 1 candy because it satisfies the above two conditions.
*/

#include<iostream>
#include<vector>
#include<numeric>
using namespace std;

// 解法一
// class Solution {
// public:
//     int candy(const vector<int>& ratings) {
//         vector<int> candy(ratings.size(), 0);
//         //从两边开始分别遍历一次
//         for (int i = 1; i < ratings.size(); ++i) {
//             if (ratings[i] > ratings[i - 1]) {
//                 candy[i] = candy[i - 1] + 1;
//             }
//         }
//         for (int i = ratings.size() - 2; i >= 0; --i) {
//             if (ratings[i] > ratings[i + 1] && candy[i] <= candy[i + 1]) {
//                 candy[i] = candy[i + 1] + 1;
//             }
//         }
//         return accumulate(candy.begin(), candy.end(), candy.size());
//     }
// };

// 解法二
class Solution {
public:
    int candy(vector<int>& ratings) {
        int num = 0;
        int old_scope = 0;
        int up = 0, down = 0;
        for (int i = 1; i < ratings.size(); ++i) {
            int new_scope = ratings[i] > ratings[i - 1] ? 1 : (ratings[i] < ratings[i - 1] ? -1 : 0);
            if ((old_scope > 0 && new_scope == 0) || (old_scope < 0 && new_scope >= 0)) {
                num += count(up) + count(down) + max(up, down);
                up = 0;
                down = 0;
            }
            if (new_scope > 0) up++;
            else if (new_scope < 0) down++;
            else num++;
            old_scope = new_scope;
        }
        num += count(up) + count(down) + max(up, down) + 1;
        return num;
    }
private:
    int count(int n) {
        return (n * (n + 1)) / 2;
    }
};

int main() {
    vector<int> test = {0, 1, 2, 5, 3, 2, 7};
    cout << Solution().candy(test) << endl;
}
