/*
 * @lc app=leetcode.cn id=441 lang=cpp
 *
 * [441] 排列硬币
 */

#include <cmath>

// @lc code=start
class Solution
{
public:
    int arrangeCoins(int n)
    {
        return static_cast<int>(sqrt(2. * static_cast<double>(n) + .25) - .5);
    }
};
// @lc code=end
