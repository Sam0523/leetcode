/*
 * @lc app=leetcode id=209 lang=cpp
 *
 * [209] Minimum Size Subarray Sum
 */

#include "common.hpp"

// @lc code=start
class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        auto first   = nums.begin();
        auto last    = nums.begin();
        auto min_len = numeric_limits<ptrdiff_t>::max();
        int  sum     = 0;
        for (;;) {
            if (sum < s) {
                if (last == nums.end())
                    break;
                sum += *last++;
            } else {
                min_len = min(min_len, last - first);
                sum -= *first++;
            }
        }
        if (min_len == numeric_limits<ptrdiff_t>::max())
            return 0;
        return min_len;
    }
};
// @lc code=end
