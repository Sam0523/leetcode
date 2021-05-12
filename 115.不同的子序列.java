/*
 * @lc app=leetcode.cn id=115 lang=java
 *
 * [115] 不同的子序列
 */

// @lc code=start
class Solution {
    public int numDistinct(String s, String t) {
        int[][] f = new int[s.length()][t.length()];
        for (int i = 0; i < s.length(); i++)
        {
            for (int j = 0; j < t.length(); j++) {
                if (i > 0) f[i][j] = f[i - 1][j];
                if (s.charAt(i) == t.charAt(j))
                f[i][j] += f[i - 1][j - 1];
            }
        }
    }
}
// @lc code=end
