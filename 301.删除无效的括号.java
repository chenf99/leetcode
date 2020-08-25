/*
 * @lc app=leetcode.cn id=301 lang=java
 *
 * [301] 删除无效的括号
 */

// @lc code=start
import java.util.List;
import java.util.ArrayList;
import java.util.LinkedList;
import java.util.Set;
import java.util.HashSet;


// 解法一 回溯
class Solution {
    private Set<String> ans = new HashSet<String>();
    private int minRemoved = Integer.MAX_VALUE;

    public List<String> removeInvalidParentheses(String s) {
        backtrack(s, 0, 0, 0, new StringBuilder(), 0);
        return new ArrayList<String>(this.ans);
    }

    private void backtrack(String s, int index, int leftCount, int rightCount, StringBuilder expression, int removed) {
        if (index == s.length()) {
            if (leftCount == rightCount && removed <= minRemoved) {
                if (removed < minRemoved) {
                    ans.clear();
                    this.minRemoved = removed;
                }
                this.ans.add(expression.toString());
            }
        }
        else {
            char c = s.charAt(index);
            int length = expression.length();
            if (c != '(' && c != ')') {
                expression.append(c);
                backtrack(s, index + 1, leftCount, rightCount, expression, removed);
                expression.deleteCharAt(length);
            }
            // 注意这个else里会前后执行两次backtrack,
            // 前一次backtrack对expression造成的修改不应该影响第二次backtrack
            // 所以需要回溯,删去对expression的修改
            else {
                // 删掉这个括号
                backtrack(s, index + 1, leftCount, rightCount, expression, removed + 1);
                // 不删掉,即加入expression
                expression.append(c);
                if (c == '(') backtrack(s, index + 1, leftCount + 1, rightCount, expression, removed);
                else if (rightCount < leftCount) backtrack(s, index + 1, leftCount, rightCount + 1, expression, removed);
                expression.deleteCharAt(length);
            }
        }
    }
}

// 解法二 有限制的回溯
class Solution {
    private Set<String> ans = new HashSet<String>();

    public List<String> removeInvalidParentheses(String s) {
        // 统计应该删除多少左括号和右括号
        int leftRem = 0, rightRem = 0;
        for (int i = 0; i < s.length(); ++i) {
            char c = s.charAt(i);
            if (c == '(') leftRem++;
            else if (c == ')') {
                if (leftRem == 0) rightRem++;
                else leftRem--;
            }
        }
        backtrack(s, 0, 0, 0, leftRem, rightRem, new StringBuilder());
        return new ArrayList(this.ans);
    }

    private void backtrack(String s, int index, int leftCount, int rightCount, int leftRem, int rightRem, StringBuilder expression) {
        if (index == s.length()) {
            if (leftCount == rightCount) this.ans.add(expression.toString());
        }
        else {
            char c = s.charAt(index);
            int length = expression.length();
            if (c != '(' && c != ')') {
                expression.append(c);
                backtrack(s, index + 1, leftCount, rightCount, leftRem, rightRem, expression);
                expression.deleteCharAt(length);
            }
            // 注意这个else里会前后执行两次backtrack,
            // 前一次backtrack对expression造成的修改不应该影响第二次backtrack
            // 所以需要回溯,删去对expression的修改
            else {
                // 删掉这个括号
                if (c == '(' && leftRem > 0) backtrack(s, index + 1, leftCount, rightCount, leftRem - 1, rightRem, expression);
                else if (rightRem > 0) backtrack(s, index + 1, leftCount, rightCount, leftRem, rightRem - 1, expression);
                // 不删掉,即加入expression
                expression.append(c);
                if (c == '(') backtrack(s, index + 1, leftCount + 1, rightCount, leftRem, rightRem, expression);
                else if (rightCount < leftCount) backtrack(s, index + 1, leftCount, rightCount + 1, leftRem, rightRem, expression);
                expression.deleteCharAt(length);
            }
        }
    }
}

// 解法三 BFS
class Solution {
    public List<String> removeInvalidParentheses(String s) {
        List<String> ans = new LinkedList<String>();
        Queue<String> level = new LinkedList<String>();
        Set<String> visited = new HashSet<String>();
        level.offer(s);
        while (!level.isEmpty() && ans.isEmpty()) {
            int size = level.size();
            visited.clear();
            for (int i = 0; i < size; ++i) {
                s = level.poll();
                if (isValid(s)) {
                    ans.add(s);
                    continue;
                }
                // 生成删除一个括号后所有可能的情况
                for (int k = 0; k < s.length(); ++k) {
                    if (s.charAt(k) == '(' || s.charAt(k) == ')') {
                        String str = s.substring(0, k) + s.substring(k + 1);
                        if (!visited.contains(str)) {
                            visited.add(str);
                            level.offer(str);
                        }
                    }
                }
            }
        }
        return ans;
    }

    private boolean isValid(String s) {
        int left = 0, right = 0;
        for (int i = 0; i < s.length(); ++i) {
            char c = s.charAt(i);
            if (c == '(') left++;
            else if (c == ')') right++;
            if (left < right) return false;
        }
        return left == right;
    }
}
// @lc code=end

