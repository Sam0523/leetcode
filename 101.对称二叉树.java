/*
 * @lc app=leetcode.cn id=101 lang=java
 *
 * [101] 对称二叉树
 */

class TreeNode {
    int val;
    TreeNode left;
    TreeNode right;

    TreeNode() {
    }

    TreeNode(int val) {
        this.val = val;
    }

    TreeNode(int val, TreeNode left, TreeNode right) {
        this.val = val;
        this.left = left;
        this.right = right;
    }
}

// @lc code=start

class Solution {
    public boolean isSymmetric(TreeNode root) {
        return isMirrored(root.left, root.right);
    }

    private boolean isMirrored(TreeNode tree1, TreeNode tree2) {
        if (tree1 == null && tree2 == null)
            return true;
        if (tree1 == null || tree2 == null || tree1.val != tree2.val)
            return false;
        return isMirrored(tree1.left, tree2.right) && isMirrored(tree1.right, tree2.left);
    }
}
// @lc code=end
