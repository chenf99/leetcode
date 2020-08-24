/*
 * @lc app=leetcode.cn id=239 lang=java
 *
 * [239] 滑动窗口最大值
 */

// @lc code=start
import java.util.Deque;
import java.util.ArrayDeque;

// 单调栈
class Solution {
    public int[] maxSlidingWindow(int[] nums, int k) {
        if (nums.length * k == 0) return new int[0];
        int[] ans = new int[nums.length - k + 1];
        // 用deque来实现一个单调递减的单栈
        Deque<Integer> deque = new ArrayDeque<Integer>();
        for (int i = 0; i < k; ++i) {
            // 移除掉队列中比nums[i]小的元素
            while (!deque.isEmpty() && nums[i] > nums[deque.getLast()]) deque.removeLast();
            deque.addLast(i);
        }
        ans[0] = nums[deque.getFirst()];
        for (int i = k; i < nums.length; ++i) {
            // 首先判断队列第一个元素是否已在窗口之外
            if (deque.getFirst() == i - k) deque.removeFirst();
            while (!deque.isEmpty() && nums[i] > nums[deque.getLast()]) deque.removeLast();
            deque.addLast(i);
            ans[i - k + 1] = nums[deque.getFirst()];
        }
        return ans;
    }
}

// 动态规划
class Solution {
    public int[] maxSlidingWindow(int[] nums, int k) {
        int n = nums.length;
        if (n * k == 0) return new int[0];
        int[] ans = new int[n - k + 1];
        int[] left = new int[n], right = new int[n];
        right[n - 1] = nums[n - 1];
        for (int i = 1; i < n; ++i) {
            if (i % k == 0) left[i] = nums[i];
            else left[i] = Math.max(left[i - 1], nums[i]);

            int j = n - i - 1;
            if ((j + 1) % k == 0) right[j] = nums[j];
            else right[j] = Math.max(right[j + 1], nums[j]);
        }
        for (int i = 0; i <= n - k; ++i) ans[i] = Math.max(right[i], left[i + k - 1]);
        return ans;
    }
}
// @lc code=end

