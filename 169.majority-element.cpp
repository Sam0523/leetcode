/*
 * @lc app=leetcode id=169 lang=cpp
 *
 * [169] Majority Element
 */

#include "common.hpp"

// @lc code=start
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int count = 0, res = 0;
        for (auto&& i : nums) {
            if (count == 0) {
                res   = i;
                count = 0;
            }
            if (res == i)
                ++count;
            else
                --count;
        }
        return count > 0 ? res : -1;
    }
};
// @lc code=end
