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

class Solution {
public:
    int candy(const vector<int>& ratings) {
        vector<int> candy(ratings.size(), 0);
        //从两边开始分别遍历一次
        for (int i = 1; i < ratings.size(); ++i) {
            if (ratings[i] > ratings[i - 1]) {
                candy[i] = candy[i - 1] + 1;
            }
        }
        for (int i = ratings.size() - 2; i >= 0; --i) {
            if (ratings[i] > ratings[i + 1] && candy[i] <= candy[i + 1]) {
                candy[i] = candy[i + 1] + 1;
            }
        }
        return accumulate(candy.begin(), candy.end(), candy.size());
    }
};

int main() {
    vector<int> test = {0, 1, 2, 5, 3, 2, 7};
    cout << Solution().candy(test) << endl;
}