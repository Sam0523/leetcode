/*
 * @lc app=leetcode.cn id=392 lang=c
 *
 * [392] 判断子序列
 */

#include <stdbool.h>
#include <string.h>
#include <stdlib.h>

// @lc code=start
bool isSubsequence(const char *s, const char *t)
{
	size_t t_len = strlen(t);
	int    next_since[t_len + 1][26];
	memset(next_since, -1, sizeof(next_since));

	for (size_t i = t_len; i > 0; i--)
	{
		for (size_t j = 0; j < 26; j++)
		{
			next_since[i - 1][j] = next_since[i][j];
		}
		next_since[i - 1][t[i - 1] - 'a'] = i;
	}

	int cur = 0;
	while (*s != '\0')
	{
		if ((cur = next_since[cur][*s++ - 'a']) == -1)
			return false;
	}
	return true;
}
// @lc code=end
