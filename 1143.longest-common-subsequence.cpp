/*
 * @lc app=leetcode id=1143 lang=cpp
 *
 * [1143] Longest Common Subsequence
 */

#include "common.hpp"

// @lc code=start
class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int f[text1.size() + 1][text2.size() + 1];
        for (int i = 0; i <= text1.size(); ++i)
            f[i][0] = 0;
        for (int j = 0; j <= text2.size(); ++j)
            f[0][j] = 0;
        for (int i = 0; i < text1.size(); ++i)
            for (int j = 0; j < text2.size(); ++j) {
                if (text1[i] == text2[j])
                    f[i + 1][j + 1] = f[i][j] + 1;
                else
                    f[i + 1][j + 1] = max(f[i][j + 1], f[i + 1][j]);
            }
        return f[text1.size()][text2.size()];
    }
};
// @lc code=end
