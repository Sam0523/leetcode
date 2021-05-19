/*
 * @lc app=leetcode id=695 lang=cpp
 *
 * [695] Max Area of Island
 */

#include "common.hpp"

// @lc code=start
class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int ret = 0;
        for (size_t i = 0; i < grid.size(); i++) {
            for (size_t j = 0; j < grid[i].size(); j++) {
                if (grid[i][j] == 1) {
                    int                   area = 0;
                    queue<pair<int, int>> q;
                    q.emplace(i, j);
                    while (!q.empty()) {
                        int r, s;
                        tie(r, s) = q.front();
                        q.pop();
                        if (r < 0 || s < 0 || r >= grid.size() ||
                            s >= grid[r].size() || grid[r][s] != 1)
                            continue;
                        grid[r][s] = 2;
                        ++area;
                        q.emplace(r - 1, s);
                        q.emplace(r + 1, s);
                        q.emplace(r, s - 1);
                        q.emplace(r, s + 1);
                    }
                    ret = max(ret, area);
                }
            }
        }
        return ret;
    }
};
// @lc code=end

int main() {
    Solution            sol;
    vector<vector<int>> grid{{1}};
    cout << sol.maxAreaOfIsland(grid);
}
