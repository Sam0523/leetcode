/*
 * @lc app=leetcode.cn id=227 lang=cpp
 *
 * [227] 基本计算器 II
 */

#include "common.hpp"

// @lc code=start
class Solution {
    static const unordered_map<char, int> op_pre;

    int invoke(int a, char op, int b) {
        switch (op) {
        case '+':
            return a + b;
            break;
        case '-':
            return a - b;
        case '*':
            return a * b;
        case '/':
            return a / b;

        default:
            break;
        }
        return 0;
    }

public:
    int calculate(string s) {
        stringstream ss(s);
        stack<int>   num_stack;
        stack<char>  op_stack;
        char         op;
        while (ss >> op) {
            if (isdigit(op)) {
                ss.unget();
                int a;
                ss >> a;
                num_stack.push(a);
                continue;
            }

            while (!op_stack.empty() &&
                   op_pre.at(op) <= op_pre.at(op_stack.top())) {
                int  a, b;
                char last_op = op_stack.top();
                op_stack.pop();
                a = num_stack.top();
                num_stack.pop();
                b = num_stack.top();
                num_stack.pop();
                num_stack.push(invoke(b, last_op, a));
            }
            op_stack.push(op);
        }
        while (!op_stack.empty()) {
            int  a, b;
            char last_op = op_stack.top();
            op_stack.pop();
            a = num_stack.top();
            num_stack.pop();
            b = num_stack.top();
            num_stack.pop();
            num_stack.push(invoke(b, last_op, a));
        }
        return num_stack.top();
    }
};

const unordered_map<char, int> Solution::op_pre = {
    {'+', 1},
    {'-', 1},
    {'*', 2},
    {'/', 2},
};
// @lc code=end

int main() {
    Solution sol;
    cout << sol.calculate("3+2*2") << endl;
    cout << sol.calculate(" 3/2 ") << endl;
    cout << sol.calculate(" 3+5 / 2 ") << endl;
    cout << sol.calculate("1*2-3/4+5*6-7*8+9/10") << endl;
    return 0;
}
