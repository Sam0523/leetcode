/*
 * @lc app=leetcode.cn id=713 lang=cpp
 *
 * [713] 乘积小于K的子数组
 */

#include "common.hpp"

// @lc code=start
class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        if (k == 0 || k == 1)
            return 0;
        int product = 1, res = 0;
        for (auto l = nums.begin(), r = nums.begin(); r != nums.end();) {
            res += r - l;
            while (r != nums.end()) {
                product *= *r++;
                if (product < k) {
                    res += r - l;
                } else {
                    break;
                }
            }
            while (product >= k) {
                product /= *l++;
            }
        }
        return res;
    }
};
// @lc code=end
