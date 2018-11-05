/*
Edit Distance

Given two words word1 and word2, find the minimum number of operations required to convert word1 to word2.

You have the following 3 operations permitted on a word:

1.Insert a character
2.Delete a character
3.Replace a character

Example 1:

Input: word1 = "horse", word2 = "ros"
Output: 3
Explanation: 
horse -> rorse (replace 'h' with 'r')
rorse -> rose (remove 'r')
rose -> ros (remove 'e')
Example 2:

Input: word1 = "intention", word2 = "execution"
Output: 5
Explanation: 
intention -> inention (remove 't')
inention -> enention (replace 'i' with 'e')
enention -> exention (replace 'n' with 'x')
exention -> exection (replace 'n' with 'c')
exection -> execution (insert 'u')
*/

#include <string>
#include <iostream>
using std::min;
using std::string;

/*解法一，没有优化空间复杂度
class Solution {
public:
    int minDistance(string word1, string word2) {
        //对于长度为i的word1子串和长度为j的word2子串
        //dist[i][j]表示这两个子串之间的编辑距离
       int m = word1.length(), n = word2.length();
       int dist[m + 1][n + 1];
       for (int i = 0; i <= m; ++i) {
           for (int j = 0; j <= n; ++j) {
               if (i == 0) dist[i][j] = j;
               else if (j == 0) dist[i][j] = i;
               else dist[i][j] = __INT_MAX__;
           }
       }

       for (int i = 1; i <= m; ++i) {
           for (int j = 1; j <= n; ++j) {
               dist[i][j] = min(min(1 + dist[i - 1][j], 1 + dist[i][j - 1]), diff(word1[i - 1], word2[j - 1]) + dist[i - 1][j - 1]);
           }
       }
       return dist[m][n];
    }
private:
    int diff(char c1, char c2) {
        return !(c1 == c2);
    }
};
*/

//解法二，优化空间复杂度
class Solution {
public:
    int minDistance(string word1, string word2) {
        //对于长度为i的word1子串和长度为j的word2子串
        //dist[i][j]表示这两个子串之间的编辑距离
       int m = word1.length(), n = word2.length();
       if (m == 0) return n;
       if (n == 0) return m;
       int dist[n + 1];
       for (int i = 0; i <= n; ++i) dist[i] = i;
       int leftNor;

       for (int i = 1; i <= m; ++i) {
           leftNor = i - 1;
           dist[0] = i;
           for (int j = 1; j <= n; ++j) {
               int tmp = dist[j];
               int diff = word1[i - 1] == word2[j - 1] ? 0 : 1;
               dist[j] = min(min(dist[j] + 1, dist[j - 1] + 1), diff + leftNor);
               leftNor = tmp;
           }
       }
       return dist[n];
    }
};

int main() {
    std::cout << Solution().minDistance("intention", "execution") << std::endl;
}