/*
 * @lc app=leetcode id=1011 lang=cpp
 *
 * [1011] Capacity To Ship Packages Within D Days
 */

#include "common.hpp"

// @lc code=start
class Solution {
public:
    int shipWithinDays(vector<int>& weights, int D) {
        int lo = *std::max_element(weights.begin(), weights.end());
        int hi = std::accumulate(weights.begin(), weights.end(), 0);
        while (lo < hi) {
            int mid  = (lo + hi) / 2;
            int days = 0, loaded = mid;
            for (auto&& weight : weights) {
                if (loaded + weight <= mid)
                    loaded += weight;
                else {
                    loaded = weight;
                    days++;
                }
            }
            if (days > D)
                lo = mid + 1;
            else
                hi = mid;
        }
        return lo;
    }
};
// @lc code=end
