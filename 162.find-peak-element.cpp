/*
 * @lc app=leetcode id=162 lang=cpp
 *
 * [162] Find Peak Element
 */

#include <iterator>
#include <vector>

using namespace std;

// @lc code=start
class Solution
{
	template <typename RandomIt>
	RandomIt findPeak(RandomIt first, RandomIt last)
	{
		switch (std::distance(first, last))
		{
		case 0:
			throw std::logic_error("Empty list");
		case 1:
			return first;
		case 2:
			return *first > *std::next(first) ? first : std::next(first);
		default:
		{
			auto mid = std::next(first, std::distance(first, last) / 2);
			if (*mid > mid[-1] && *mid > mid[1])
				return mid;
			else if (mid[-1] > mid[1])
				return findPeak(first, mid);
			else
				return findPeak(mid + 1, last);
		}
		}
	}

public:
	int findPeakElement(vector<int>& nums)
	{
		return findPeak(nums.begin(), nums.end()) - nums.begin();
	}
};
// @lc code=end
