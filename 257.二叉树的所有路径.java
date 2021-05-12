import java.util.LinkedList;
import java.util.List;

/*
 * @lc app=leetcode.cn id=257 lang=java
 *
 * [257] 二叉树的所有路径
 */

// Definition for a binary tree node.
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
    public List<String> binaryTreePaths(TreeNode root) {
        List<String> ret = new LinkedList<>();
        if (root != null) {
            if (root.left == null && root.right == null) {
                ret.add(String.valueOf(root.val));
            } else {
                ret.addAll(binaryTreePaths(root.left));
                ret.addAll(binaryTreePaths(root.right));
                ret.replaceAll(s -> String.valueOf(root.val) + "->" + s);
            }
        }
        return ret;
    }
}
// @lc code=end
