/*
 * @lc app=leetcode.cn id=4 lang=cpp
 *
 * [4] 寻找两个正序数组的中位数
 */

#include "common.hpp"

// @lc code=start
class Solution {
public:
    int findKthSortedArrays(size_t k,
                            const vector<int>& nums1,
                            const vector<int>& nums2) {
        // find boundary in nums1
        size_t lo = k > nums2.size() ? k - nums2.size() : 0U;
        size_t hi = std::min(nums1.size(), k);
        while (lo < hi) {
            auto bound1 = (lo + hi) / 2;
            auto bound2 = k - bound1;
            if (bound1 < nums1.size() && bound2 > 0 &&
                nums1[bound1] < nums2[bound2 - 1]) {
                lo = bound1 + 1;
            } else if (bound1 > 0 && bound2 < nums2.size() &&
                       nums1[bound1 - 1] > nums2[bound2]) {
                hi = bound1 - 1;
            } else {
                lo = hi = bound1;
                break;
            }
        }
        if (lo >= nums1.size()) {
            return nums2[k - lo];
        }
        if (k - lo >= nums2.size()) {
            return nums1[lo];
        }
        return std::min(nums1[lo], nums2[k - lo]);
    }

    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if (nums1.size() > nums2.size()) {
            std::swap(nums1, nums2);
        }
        size_t total = nums1.size() + nums2.size();
        return (findKthSortedArrays(total / 2, nums1, nums2) +
                findKthSortedArrays((total - 1) / 2, nums1, nums2)) /
               2.0;
    }
};

// @lc code=end

int main() {
    Solution sol;

    assert(sol.findKthSortedArrays(0, {}, {1, 2, 3}) == 1);
    assert(sol.findKthSortedArrays(1, {}, {1, 2, 3}) == 2);
    assert(sol.findKthSortedArrays(2, {}, {1, 2, 3}) == 3);

    assert(sol.findKthSortedArrays(0, {1, 1}, {1, 2, 3}) == 1);
    assert(sol.findKthSortedArrays(1, {1, 1}, {1, 2, 3}) == 1);
    assert(sol.findKthSortedArrays(2, {1, 1}, {1, 2, 3}) == 1);
    assert(sol.findKthSortedArrays(3, {1, 1}, {1, 2, 3}) == 2);
    assert(sol.findKthSortedArrays(4, {1, 1}, {1, 2, 3}) == 3);

    assert(sol.findKthSortedArrays(0, {1, 1}, {1, 1, 1}) == 1);
    assert(sol.findKthSortedArrays(4, {1, 1}, {1, 1, 1}) == 1);
}
