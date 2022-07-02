/*
 * @lc app=leetcode.cn id=556 lang=cpp
 *
 * [556] 下一个更大元素 III
 */

#include "common.hpp"

// @lc code=start
class Solution {
public:
    int nextGreaterElement(int n) {
        auto s = to_string(n);
        auto p = s.rbegin() + 1;
        for (; p != s.rend(); ++p) {
            if (p[0] < p[-1]) {
                break;
            }
        }
        if (p == s.rend()) {
            return -1;
        }
        auto q = upper_bound(s.rbegin(), p, *p);
        swap(*p, *q);
        reverse(s.rbegin(), p);
        try {
            return stoi(s);
        } catch (const out_of_range&) {
            return -1;
        }
    }
};
// @lc code=end
