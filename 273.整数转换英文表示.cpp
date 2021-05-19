/*
 * @lc app=leetcode.cn id=273 lang=cpp
 *
 * [273] 整数转换英文表示
 */

#include "common.hpp"

// @lc code=start
class Solution {
    static const map<int, string> simpleNumber;

    string numberBelow1000(int num) {
        string ret;
        int    h = num / 100;
        num %= 100;
        if (h > 0) {
            ret += simpleNumber.at(h) + ' ' + simpleNumber.at(100) + ' ';
        }
        if (num >= 20) {
            ret += simpleNumber.at(num / 10 * 10) + ' ' +
                   simpleNumber.at(num % 10);
        } else {
            ret += simpleNumber.at(num);
        }
        while (ret.back() == ' ')
            ret.pop_back();
        return ret;
    }

public:
    string numberToWords(int num) {
        if (num == 0)
            return "Zero";
        string ret;
        for (int base = 1000000000; base > 0; base /= 1000) {
            int sub = num / base;
            num %= base;
            if (sub > 0) {
                ret += numberBelow1000(sub) + ' ';
                if (base != 1)
                    ret += simpleNumber.at(base) + ' ';
            }
        }
        while (ret.back() == ' ')
            ret.pop_back();
        return ret;
    }
};

const map<int, string> Solution::simpleNumber{
    {0, ""},
    {1, "One"},
    {2, "Two"},
    {3, "Three"},
    {4, "Four"},
    {5, "Five"},
    {6, "Six"},
    {7, "Seven"},
    {8, "Eight"},
    {9, "Nine"},
    {10, "Ten"},
    {11, "Eleven"},
    {12, "Twelve"},
    {13, "Thirteen"},
    {14, "Fourteen"},
    {15, "Fifteen"},
    {16, "Sixteen"},
    {17, "Seventeen"},
    {18, "Eighteen"},
    {19, "Nineteen"},
    {20, "Twenty"},
    {30, "Thirty"},
    {40, "Forty"},
    {50, "Fifty"},
    {60, "Sixty"},
    {70, "Seventy"},
    {80, "Eighty"},
    {90, "Ninety"},
    {100, "Hundred"},
    {1000, "Thousand"},
    {1000000, "Million"},
    {1000000000, "Billion"},
};
// @lc code=end

int main(void) {
    Solution sol;
    cout << sol.numberToWords(1) << endl;
    cout << sol.numberToWords(14) << endl;
    cout << sol.numberToWords(23) << endl;
    cout << sol.numberToWords(890) << endl;
    cout << sol.numberToWords(100) << endl;
    cout << sol.numberToWords(112) << endl;
    cout << sol.numberToWords(134) << endl;
    cout << sol.numberToWords(20213) << endl;
    cout << sol.numberToWords(1000000000) << endl;
}
