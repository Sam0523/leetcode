/*
 * @lc app=leetcode.cn id=239 lang=cpp
 *
 * [239] 滑动窗口最大值
 */

#include "common.hpp"

// @lc code=start
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int> &nums, int k) {
        // (value, index)
        using queue_item = pair<int, int>;
        auto cmp = [](const queue_item &a, const queue_item &b) {
            return a.first < b.first;
        };
        vector<int> ret;
        --k;
        ret.reserve(nums.size() - k);
        priority_queue pq(cmp, vector<queue_item>{});
        for (int i = 0; i < k; ++i) {
            pq.emplace(nums[i], i);
        }
        for (int i = k; i < nums.size(); ++i) {
            pq.emplace(nums[i], i);
            ret.push_back(pq.top().first);
            while (!pq.empty() && pq.top().second <= i - k) {
                pq.pop();
            }
        }
        return ret;
    }
};
// @lc code=end
