/*
 * @lc app=leetcode.cn id=289 lang=cpp
 *
 * [289] 生命游戏
 */

#include "common.hpp"

// @lc code=start
class Solution {
public:
    void gameOfLife(vector<vector<int>> &board) {
        size_t const m = board.size(), n = board[0].size();
        for (int i = 0; i < m; ++i)
            for (int j = 0; j < n; ++j) {
                int alive_neighbor = 0;
                for (auto p : {-1, 0, 1})
                    for (auto q : {-1, 0, 1}) {
                        if (i + p >= 0 && i + p < m && j + q >= 0 &&
                            j + q < n && (p != 0 || q != 0))
                            alive_neighbor += board[i + p][j + q] & 1;
                    }
                if (alive_neighbor == 2)
                    board[i][j] |= board[i][j] << 4;
                else if (alive_neighbor == 3)
                    board[i][j] |= 1 << 4;
            }
        for (auto &&row : board)
            for (auto &&cell : row)
                cell >>= 4;
    }
};

// @lc code=end
