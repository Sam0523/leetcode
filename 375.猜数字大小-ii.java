/*
 * @lc app=leetcode.cn id=375 lang=java
 *
 * [375] 猜数字大小 II
 */

// @lc code=start
class Solution {
    public int getMoneyAmount(int n) {
        int[][] f = new int[n + 2][n + 2];
        for (int k = 2; k <= n; k++) {
            for (int i = 1; i + k <= n + 1; i++) {
                f[i][i + k] = Integer.MAX_VALUE;
                for (int j = i; j < i + k; j++) {
                    f[i][i + k] = Integer.min(f[i][i + k], j + Integer.max(f[i][j], f[j + 1][i + k]));
                }
            }
        }
        return f[1][n + 1];
    }
}
// @lc code=end
