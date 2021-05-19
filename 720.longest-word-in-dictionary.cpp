/*
 * @lc app=leetcode id=720 lang=cpp
 *
 * [720] Longest Word in Dictionary
 */

#include "common.hpp"

// @lc code=start
class Solution {
public:
    string longestWord(vector<string>& words) {
        string ret;
        sort(words.begin(), words.end());
        for (auto it = words.begin() + 1; it < words.end(); it++) {
            if (it->compare(0, it->size() - 1, it[-1]))
        }
    }
};
// @lc code=end
