import java.util.Arrays;
import java.util.Comparator;
import java.util.ArrayList;

/*
 * @lc app=leetcode.cn id=406 lang=java
 *
 * [406] 根据身高重建队列
 */

// @lc code=start
class Solution {
    class Comp implements Comparator<int[]> {
        public int compare(int[] a, int[] b) {
            if (a[0] != b[0])
                return b[0] - a[0];
            else
                return a[1] - b[1];
        }
    }

    public int[][] reconstructQueue(int[][] people) {
        ArrayList<int[]> ret = new ArrayList<int[]>();
        Arrays.sort(people, new Comp());
        for (int[] is : people) {
            int i = 0;
            for (int j = 0; j < is[1]; i++) {
                if (ret.get(i)[0] >= is[0])
                    j++;
            }
            ret.add(i, is);
        }
        return ret.toArray(people);
    }
}
// @lc code=end
