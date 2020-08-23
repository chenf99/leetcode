/*
 * @lc app=leetcode.cn id=406 lang=java
 *
 * [406] 根据身高重建队列
 */

// @lc code=start
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Comparator;

class Solution {
    public int[][] reconstructQueue(int[][] people) {
        ArrayList<int[]> list = new ArrayList<int[]>();
        Arrays.sort(people, new Comparator<int[]>() {
            @Override
            public int compare(int[] a1, int[] a2) {
                if (a1[0] == a2[0]) return a1[1] - a2[1];
                else return a2[0] - a1[0];
            }
        });
        for (int i = 0; i < people.length; ++i) list.add(people[i][1], people[i]);
        return list.toArray(new int[0][]);
    }
}
// @lc code=end

