/*
 * @lc app=leetcode id=201 lang=cpp
 *
 * [201] Bitwise AND of Numbers Range
 *
 * https://leetcode.com/problems/bitwise-and-of-numbers-range/description/
 *
 * algorithms
 * Medium (35.62%)
 * Total Accepted:    84.1K
 * Total Submissions: 232.4K
 * Testcase Example:  '5\n7'
 *
 * Given a range [m, n] where 0 <= m <= n <= 2147483647, return the bitwise AND
 * of all numbers in this range, inclusive.
 * 
 * Example 1:
 * 
 * 
 * Input: [5,7]
 * Output: 4
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: [0,1]
 * Output: 0
 */
#include <iostream>

class Solution {
public:
    int rangeBitwiseAnd(int m, int n) {
        unsigned int mask = 0x7fffffff;
        
        while ((m & mask) != (n & mask)) {
            mask <<= 1;
        }
        
        return m & mask;
    }
};

// int main() {
//     std::cout << Solution().rangeBitwiseAnd(26, 30) << std::endl;
// }