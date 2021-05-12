/*
 * @lc app=leetcode.cn id=392 lang=cpp
 *
 * [392] 判断子序列
 */

#include <iostream>
#include <string>
#include <vector>
#include <array>

using namespace std;

// @lc code=start
class Solution
{
public:
	bool isSubsequence(string s, string t)
	{
		std::vector<std::array<int, 26>> next_since(t.size() + 1);
		std::fill(next_since[t.size()].begin(),
		          next_since[t.size()].end(), -1);
		for (size_t i = t.size(); i > 0; i--)
		{
			next_since[i - 1] = next_since[i];

			next_since[i - 1][t[i - 1] - 'a'] = i;
		}

		int cur = 0;
		for (auto &&c : s)
		{
			if ((cur = next_since[cur][c - 'a']) == -1)
				return false;
		}
		return true;
	}
};
// @lc code=end

int main()
{
	using namespace std::string_literals;
	Solution sol;
	cout << sol.isSubsequence("abc"s, "ahbgdc"s);
}
