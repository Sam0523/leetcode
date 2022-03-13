/*
 * @lc app=leetcode.cn id=1371 lang=cpp
 *
 * [1371] 每个元音包含偶数次的最长子字符串
 */
#include "common.hpp"

// @lc code=start
class Solution {
public:
    int findTheLongestSubstring(string s) {
        std::unordered_map<char, int> vowel_order = {
            {'a', 0}, {'e', 1}, {'i', 2}, {'o', 3}, {'u', 4}};
        std::vector<std::array<int, 32>> f(s.size() + 1);
        int                              ans = 0;
        for (auto &&arr : f)
            for (auto &&val : arr)
                val = 0;
        for (size_t i = 0; i < s.size(); ++i) {
            switch (s[i]) {
            case 'a':
            case 'e':
            case 'i':
            case 'o':
            case 'u':
                for (int j = 0; j < 32; ++j) {
                    if (f[i][j] != 0)
                        f[i + 1][j ^ (1 << vowel_order[s[i]])] = f[i][j] + 1;
                }
                if (f[i + 1][1 << vowel_order[s[i]]] == 0)
                    f[i + 1][1 << vowel_order[s[i]]] = 1;
                break;
            default:
                for (int j = 0; j < 32; ++j) {
                    if (f[i][j] != 0)
                        f[i + 1][j] = f[i][j] + 1;
                }
                if (f[i + 1][0] == 0)
                    f[i + 1][0] = 1;
                break;
            }
            ans = std::max(ans, f[i + 1][0]);
        }
        return ans;
    }
};

// @lc code=end
