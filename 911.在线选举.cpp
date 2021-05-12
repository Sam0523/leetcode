/*
 * @lc app=leetcode.cn id=911 lang=cpp
 *
 * [911] 在线选举
 */

#include <vector>
#include <algorithm>

using namespace std;

// @lc code=start
class TopVotedCandidate
{
    vector<pair<int, int>> result;

public:
    TopVotedCandidate(vector<int>& persons, vector<int>& times)
    {
        const size_t N = persons.size();
        vector<int>  votes(N, 0);

        result.emplace_back(-1, 0);
        for (size_t i = 0; i < N; i++)
        {
            auto currentTop = result.back().second;
            votes[persons[i]]++;
            if (votes[persons[i]] >= votes[currentTop] &&
                persons[i] != currentTop)
                result.emplace_back(times[i], persons[i]);
        }
    }

    int q(int t)
    {
        return (upper_bound(result.begin(), result.end(), t,
                            [](const int& a, const pair<int, int>& b) {
                                return a < b.first;
                            }) -
                1)
            ->second;
    }
};

/**
 * Your TopVotedCandidate object will be instantiated and called as such:
 * TopVotedCandidate* obj = new TopVotedCandidate(persons, times);
 * int param_1 = obj->q(t);
 */
// @lc code=end
