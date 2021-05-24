/*
 * @lc app=leetcode id=719 lang=cpp
 *
 * [719] Find K-th Smallest Pair Distance
 */

#include <algorithm>
#include <queue>
#include <utility>
#include <vector>

using namespace std;

// @lc code=start
class Solution {
public:
    int smallestDistancePair(vector<int>& nums, int k) {
        // sort(nums.begin(), nums.end());
        priority_queue<int> dist;
        for (auto it = nums.begin(); it != nums.end(); ++it) {
            for (auto jt = nums.begin(); jt != it; ++jt) {
                if (int d = abs(*jt - *it); dist.size() < k || d < dist.top()) {
                    dist.push(d);
                }
                // dist.push(abs(*jt - *it));
                if (dist.size() > k) {
                    dist.pop();
                }
            }
        }
        return dist.top();
    }
};
// @lc code=end
