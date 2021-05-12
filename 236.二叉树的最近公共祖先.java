/*
 * @lc app=leetcode.cn id=236 lang=java
 *
 * [236] 二叉树的最近公共祖先
 */

// @lc code=start
/**
 * Definition for a binary tree node. public class TreeNode { int val; TreeNode
 * left; TreeNode right; TreeNode(int x) { val = x; } }
 */
class Solution {
    private TreeNode p, q, ancestor;

    public TreeNode lowestCommonAncestor(TreeNode root, TreeNode p, TreeNode q) {
        this.p = p;
        this.q = q;
        dfs(root);
        return ancestor;
    }

    enum subTreeStat {
        FIND_NONE, FIND_P, FIND_Q, FIND_BOTH,
    }

    private subTreeStat dfs(TreeNode root) {
        if (root == null)
            return subTreeStat.FIND_NONE;
        subTreeStat left = dfs(root.left);
        if (left == subTreeStat.FIND_BOTH)
            return left;
        subTreeStat right = dfs(root.right);
        if (right == subTreeStat.FIND_BOTH)
            return right;
        int ret = left.ordinal() + right.ordinal();
        if (root == p)
            ret += subTreeStat.FIND_P.ordinal();
        if (root == q)
            ret += subTreeStat.FIND_Q.ordinal();
        if (ret == subTreeStat.FIND_BOTH.ordinal()) {
            this.ancestor = root;
        }
        return subTreeStat.values()[ret];
    }
}
// @lc code=end
