/*
 * @lc app=leetcode.cn id=5227 lang=cpp
 *
 * [5227] K 次操作后最大化顶端元素
 */
#include "common.hpp"

// @lc code=start
class Solution {
public:
    int maximumTop(vector<int>& nums, int k) {
        int max = -1;
        if (k > nums.size()) {
            if (nums.size() == 1 && (k - nums.size()) % 2 == 0)
                return -1;
            return *std::max_element(nums.begin(), nums.end());
        }
        if (k > 1)
            max = std::max(
                max, *std::max_element(nums.begin(), nums.begin() + k - 1));
        if (k < nums.size())
            max = std::max(max, nums[k]);
        return max;
    }
};

// @lc code=end
