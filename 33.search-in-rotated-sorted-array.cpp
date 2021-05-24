/*
 * @lc app=leetcode id=33 lang=cpp
 *
 * [33] Search in Rotated Sorted Array
 */

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

// @lc code=start
class Solution {
public:
    int search(vector<int>& nums, int target) {
        if (nums.empty())
            return -1;
        auto lo = nums.begin();
        auto hi = nums.end() - static_cast<int>(!nums.empty());
        while (hi - lo > 1) {
            auto mid = lo + (hi - lo) / 2;
            if (*mid >= *lo)
                lo = mid;
            else if (*mid <= *hi)
                hi = mid;
        }
        vector<int>::iterator pos;
        if (target <= nums.back()) {
            pos = lower_bound(hi, nums.end(), target);
        } else if (target >= nums.front()) {
            pos = lower_bound(nums.begin(), hi, target);
        } else {
            return -1;
        }

        if (*pos == target) {
            return pos - nums.begin();
        }
        return -1;
    }
};
// @lc code=end

int main() {
    Solution    sol;
    vector<int> nums;
    cout << sol.search(nums, 0) << endl;
    nums = {0};
    cout << sol.search(nums, 0) << endl;
    nums = {0, 1};
    cout << sol.search(nums, 0) << endl;
    nums = {1, 0};
    cout << sol.search(nums, 0) << endl;
}
