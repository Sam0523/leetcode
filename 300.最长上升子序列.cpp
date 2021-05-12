/*
 * @lc app=leetcode.cn id=300 lang=cpp
 *
 * [300] 最长上升子序列
 */

#include <vector>
#include <algorithm>

using namespace std;

// @lc code=start
class Solution
{
public:
    int lengthOfLIS(vector<int>& nums)
    {
        vector<int> lis;
        lis.reserve(nums.size());
        for (auto&& i : nums)
        {
            auto it = lower_bound(lis.begin(), lis.end(), i);
            if (it == lis.end())
            {
                lis.push_back(i);
            }
            else
            {
                *it = i;
            }
        }
        return lis.size();
    }
};
// @lc code=end
