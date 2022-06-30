/*
 * @lc app=leetcode.cn id=904 lang=cpp
 *
 * [904] 水果成篮
 */

#include "common.hpp"

// @lc code=start
class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int a = -1, b = -1;
        std::ptrdiff_t ans = 0;
        auto two_bound = fruits.begin();
        auto one_bound = fruits.begin();
        for (auto it = fruits.begin(); it != fruits.end(); ++it) {
            if (*it == *one_bound) {
                continue;
            }
            if (*it == a || *it == b) {
                one_bound = it;
                continue;
            }
            ans = std::max(ans, it - two_bound);
            two_bound = one_bound;
            one_bound = it;
            a = *two_bound;
            b = *it;
        }
        ans = std::max(ans, fruits.end() - two_bound);
        return ans;
    }
};
// @lc code=end
