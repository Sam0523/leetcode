/*
 * @lc app=leetcode.cn id=49 lang=cpp
 *
 * [49] 字母异位词分组
 */

#include "common.hpp"

// @lc code=start
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string> &strs) {
        std::unordered_map<string, std::vector<string>> m;
        for (auto &str : strs) {
            m[countChars(str)].push_back(std::move(str));
        }
        vector<vector<string>> ret;
        ret.reserve(m.size());
        for (auto &&it : m) {
            ret.push_back(std::move(it.second));
        }
        return ret;
    }

    string countChars(const string &str) {
        string ret(26, '\0');
        for (auto ch : str) {
            ret[ch - 'a']++;
        }
        return ret;
    }
};
// @lc code=end
