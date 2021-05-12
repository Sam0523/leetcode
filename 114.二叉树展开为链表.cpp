/*
 * @lc app=leetcode.cn id=114 lang=cpp
 *
 * [114] 二叉树展开为链表
 */
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
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    void flatten(TreeNode *root) { flatten_impl(root); }

private:
    TreeNode *&flatten_impl(TreeNode *&root) {
        if (root == nullptr) {
            return root;
        }
        auto &left_tail  = flatten_impl((root)->left);
        auto &right_tail = flatten_impl((root)->right);
        left_tail        = (root)->right;
        (root)->right    = (root)->left;
        (root)->left     = nullptr;
        return right_tail == nullptr ? right_tail : left_tail;
    }
};
// @lc code=end

int main() {
    Solution sol;
    auto     root =
        new TreeNode(1, new TreeNode(2, new TreeNode(3), nullptr), nullptr);
    sol.flatten(root);
}
