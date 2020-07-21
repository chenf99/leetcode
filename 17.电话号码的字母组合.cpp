/*
 * @lc app=leetcode.cn id=17 lang=cpp
 *
 * [17] 电话号码的字母组合
 */

// @lc code=start
#include <vector>
#include <string>
#include <unordered_map>
using namespace std;

// 解法一
// class Solution {
// public:
//     vector<string> letterCombinations(string digits) {
//         unordered_map<char, vector<string>> m{
//             {'2', {"a","b","c"}}, {'3', {"d","e","f"}}, {'4', {"g","h","i"}}, \
//             {'5', {"j","k","l"}}, {'6', {"m","n","o"}}, {'7', {"p","q","r","s"}}, \
//             {'8', {"t","u","v"}}, {'9', {"w","x","y","z"}}};
//         vector<string> result;
//         for (auto d : digits) {
//             if (result.size() == 0) result.insert(result.begin(), m[d].begin(), m[d].end());
//             else {
//                 vector<string> tmp;
//                 for (auto it = result.begin(); it != result.end(); ) {
//                     string str = *it;
//                     it = result.erase(it);
//                     for (auto c : m[d]) tmp.push_back(str + c);
//                 }
//                 result.insert(result.begin(), tmp.begin(), tmp.end());
//             }
//         }
//         return result;
//     }
// };

// 解法二
class Solution {
public:
    vector<string> letterCombinations(string digits) {
        if (!digits.size()) return {};
        vector<string> result;
        dfs(result, digits, 0);
        return result;
    }
private:
    unordered_map<char, vector<string>> m{
        {'2', {"a","b","c"}}, {'3', {"d","e","f"}}, {'4', {"g","h","i"}}, \
        {'5', {"j","k","l"}}, {'6', {"m","n","o"}}, {'7', {"p","q","r","s"}}, \
        {'8', {"t","u","v"}}, {'9', {"w","x","y","z"}}};
    string tmp = "";
    void dfs(vector<string>& result, const string& digits, int index) {
        if (index == digits.size()) {
            result.push_back(tmp);
            return;
        }
        for (int i = 0; i < m[digits[index]].size(); ++i) {
            tmp += m[digits[index]][i];
            dfs(result, digits, index + 1);
            tmp.pop_back();
        }
    }
};
// @lc code=end

