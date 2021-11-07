/*
 * @lc app=leetcode.cn id=4 lang=cpp
 *
 * [4] 寻找两个正序数组的中位数
 */

#include "common.hpp"

// @lc code=start
class Solution {
public:
    template <typename InputIt>
    double findMedianSorted(InputIt first, InputIt last) {
        auto count = std::distance(first, last);
        if (count != 0)
            return static_cast<double>(
                       *std::next(first, count / 2) +
                       *std::next(first, count / 2 - !(count % 2))) /
                   2.0;
        else
            return numeric_limits<double>::quiet_NaN();
    }
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        auto first1 = nums1.begin(), last1 = nums1.end();
        auto first2 = nums2.begin(), last2 = nums2.end();
        if (nums1.size() == 0)
            return findMedianSorted(first2, last2);
        if (nums2.size() == 0)
            return findMedianSorted(first1, last1);

        size_t count1 = nums1.size(), count2 = nums2.size();
        for (;;) {
            double med1 = findMedianSorted(first1, last1);
            double med2 = findMedianSorted(first2, last2);
            size_t step = std::min(count1 / 2 - !(count1 % 2),
                                   count2 / 2 - !(count2 % 2));
            if (step == 0)
                break;
            else if (med1 < med2) {
                first1 += step;
                last2 -= step;
            } else if (med1 > med2) {
                first2 += step;
                last1 -= step;
            } else
                return med1;
            count1 = last1 - first1;
            count2 = last2 - first2;
        }

        if (count1 > 4) {
            first1 += (count1 - 3) / 2;
            last1 -= (count1 - 3) / 2;
        }
        if (count2 > 4) {
            first2 += (count2 - 3) / 2;
            last2 -= (count2 - 3) / 2;
        }
        std::vector<int> v(first1, last1);
        v.insert(v.end(), first2, last2);
        std::sort(v.begin(), v.end());
        return findMedianSorted(v.begin(), v.end());
    }
};

// @lc code=end
