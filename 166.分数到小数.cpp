/*
 * @lc app=leetcode.cn id=166 lang=cpp
 *
 * [166] 分数到小数
 */

#include <iostream>
#include <vector>
#include <string>

using namespace std;

// @lc code=start
class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        string ret;

        if (numerator * denominator < 0) {
            ret.push_back('-');
        }
        numerator   = abs(numerator);
        denominator = abs(denominator);

        ret += to_string(numerator / denominator);
        numerator %= denominator;
        if (numerator == 0) {
            return ret;
        }

        ret.push_back('.');
        vector<int> remains(denominator, 0);
        while (numerator != 0) {
            if (remains[numerator] == 0)
                remains[numerator] = ret.size();
            else {
                ret.insert(remains[numerator], 1, '(');
                ret.push_back(')');
                return ret;
            }

            numerator *= 10;
            ret += to_string(numerator / denominator);
            numerator %= denominator;
        }
        return ret;
    }
};
// @lc code=end

int main() {
    Solution sol;
    cout << sol.fractionToDecimal(1, 2) << endl;
    cout << sol.fractionToDecimal(2, 1) << endl;
    cout << sol.fractionToDecimal(2, 3) << endl;
    cout << sol.fractionToDecimal(3, 2) << endl;
    cout << sol.fractionToDecimal(22, 7) << endl;
    cout << sol.fractionToDecimal(-22, 7) << endl;
    cout << sol.fractionToDecimal(22, -7) << endl;
    cout << sol.fractionToDecimal(-22, -7) << endl;
    cout << sol.fractionToDecimal(1, 214748364) << endl;
}
