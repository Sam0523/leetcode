/*
 * @lc app=leetcode.cn id=406 lang=cpp
 *
 * [406] 根据身高重建队列
 */

#include "common.hpp"

// @lc code=start
class Solution {
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>> &people) {
        std::sort(people.begin(), people.end(),
                  [](const vector<int> &a, const vector<int> &b) -> bool {
                      if (a[0] != b[0])
                          return b[0] < a[0];
                      else
                          return a[1] < b[1];
                  });
        for (auto it = people.begin(); it != people.end(); it++) {
            auto ptr = people.begin();
            for (int i = 0; i < (*it)[1]; ptr++) {
                if ((*ptr)[0] >= (*it)[0])
                    i++;
            }
            for (; ptr != it; ptr++)
                std::swap(*it, *ptr);
        }
        return people;
    }
};
// @lc code=end

int main(void) {
    vector<vector<int>> people = {{7, 0}, {4, 4}, {7, 1},
                                  {5, 0}, {6, 1}, {5, 2}};
    Solution            sol;
    people = sol.reconstructQueue(people);
    for (auto &&i : people) {
        std::cout << i[0] << ' ' << i[1] << std::endl;
    }
    return 0;
}
