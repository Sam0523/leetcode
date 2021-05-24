/*
 * @lc app=leetcode.cn id=95 lang=cpp
 *
 * [95] 不同的二叉搜索树 II
 */

#include <algorithm>
#include <map>
#include <utility>
#include <vector>

using namespace std;

struct TreeNode {
    int       val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) :
        val(x), left(left), right(right) {}
};

// @lc code=start

class Solution {
public:
    vector<TreeNode *> generateTrees(int n) {
        // dp[i][j] means range start at i, length j
        vector<vector<vector<TreeNode *>>> dp(n + 1);
        for (int i = 0; i <= n; i++) {
            dp[i].resize(n + 1 - i);
            dp[i][0].push_back(nullptr);
        }

        // k for range length
        for (int k = 1; k <= n; k++) {
            // i for range starts
            for (int i = 0; i <= n - k; i++) {
                // j for root
                for (int j = i; j < i + k; j++) {
                    // left part
                    for (auto &&l : dp[i][j - i]) {
                        // right part
                        for (auto &&r : dp[j + 1][k - (j - i + 1)]) {
                            dp[i][k].push_back(new TreeNode(j + 1, l, r));
                        }
                    }
                }
            }
        }
        return dp[0][n];
    }
};
// @lc code=end
