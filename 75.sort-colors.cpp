/*
 * @lc app=leetcode id=75 lang=cpp
 *
 * [75] Sort Colors
 */

#include "common.hpp"

// @lc code=start
class Solution {
public:
    void sortColors(vector<int>& nums) {
        auto i = nums.begin();
        auto j = nums.end();
        for (auto it = i; it < j;) {
            if (*it == 0)
                swap(*it++, *i++);
            else if (*it == 2)
                swap(*it, *--j);
            else
                ++it;
        }
    }
};
// @lc code=end
