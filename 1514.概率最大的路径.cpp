/*
 * @lc app=leetcode.cn id=1514 lang=cpp
 *
 * [1514] 概率最大的路径
 */

#include "common.hpp"

// @lc code=start
class Solution {
public:
    double maxProbability(int                  n,
                          vector<vector<int>>& edges,
                          vector<double>&      succProb,
                          int                  start,
                          int                  end) {
        vector<double>      prob(n, 0.0);
        vector<vector<int>> neighbor(n);
        for (size_t i = 0; i < edges.size(); i++) {
            neighbor[edges[i][0]].push_back(i);
            neighbor[edges[i][1]].push_back(i);
        }
        prob[start] = 1;
        auto cmp    = [&](const int& a, const int& b) {
            return prob[a] < prob[b];
        };
        priority_queue<int, vector<int>, decltype(cmp)> q(cmp);
        q.push(start);
        for (;;) {
            auto u = q.top();
            q.pop();
        }
    }
};
// @lc code=end
