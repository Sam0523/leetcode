/*
 * @lc app=leetcode.cn id=394 lang=cpp
 *
 * [394] 字符串解码
 */

#include "common.hpp"

// @lc code=start
class Solution {
public:
    string decodeString(string s) { return helper(s.c_str(), nullptr); }

    // parse start from first, store end point to *last (next unparsed char)
    string helper(const char *first, const char **last) {
        string ret;
        for (; *first != '\0'; ++first) {
            if (isalpha(*first)) {
                ret.push_back(*first);
            } else if (isdigit(*first)) {
                char *p;
                int n = strtol(first, &p, 10);
                first = p;
                assert(*first == '[');
                ++first;
                string str = helper(first, &first);
                for (; n > 0; --n) {
                    ret.append(str);
                }
                assert(*first == ']');
            } else if (*first == ']') {
                // unmatched closing bracket; end of substring
                break;
            }
        }
        if (last != nullptr) {
            *last = first;
        }
        return ret;
    }
};
// @lc code=end
