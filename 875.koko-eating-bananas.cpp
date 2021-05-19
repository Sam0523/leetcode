/*
 * @lc app=leetcode id=875 lang=cpp
 *
 * [875] Koko Eating Bananas
 */

#include "common.hpp"

// @lc code=start
class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int H) {
        int lo = 1, hi = *std::max_element(piles.begin(), piles.end());
        while (lo < hi) {
            int mid  = (lo + hi) / 2;
            int time = 0;
            std::for_each(piles.begin(), piles.end(),
                          [&](int i) { time += i / mid + (i % mid != 0); });
            if (time > H)
                lo = mid + 1;
            else
                hi = mid;
        }
        return lo;
    }
};
// @lc code=end

int main() {
    Solution    sol;
    vector<int> v{3, 6, 7, 11};
    int         H = 8;
    cout << sol.minEatingSpeed(v, H) << endl;
}
