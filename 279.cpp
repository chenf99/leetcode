/*
Given a positive integer n, find the least number of perfect square numbers 
(for example, 1, 4, 9, 16, ...) which sum to n.

Example 1:

Input: n = 12
Output: 3 
Explanation: 12 = 4 + 4 + 4.
Example 2:

Input: n = 13
Output: 2
Explanation: 13 = 4 + 9.

*/

#include <iostream>
#include <cmath>
#include <vector>
#include <climits>
using namespace std;

/*DP解法
class Solution {
public:
    int numSquares(int n) {
        vector<int> num(n + 1, __INT_MAX__);
        num[0] = 0;
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j * j <= i; ++j) {
                num[i] = min(num[i - j * j] + 1, num[i]);
            }
        }
        return num[n];
    }
};
*/

//四平方和数学解法
class Solution {
public:
    int numSquares(int n) {
        //是4的倍数的话可以除以4，不影响结果
        while (n % 4 == 0) n /= 4;
        //满足8m + 7的数
        if (n % 8 == 7) return 4;
        else {
            //能否拆成两个平方数之和
            for (int i = 0; i * i <= n; ++i) {
                int tmp = sqrt(n - i * i);
                if (tmp * tmp == n - i * i) {
                    return !!i + !!tmp;
                }
            }
            return 3;
        }
    }
};

int main() {
    cout << Solution().numSquares(13) << endl;
}