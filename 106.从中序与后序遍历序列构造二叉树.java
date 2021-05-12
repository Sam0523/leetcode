
/*
 * @lc app=leetcode.cn id=106 lang=java
 *
 * [106] 从中序与后序遍历序列构造二叉树
 */

// @lc code=start
import java.util.Hashtable;

class Solution {
    Hashtable<Integer, Integer> inorderPos = new Hashtable<Integer, Integer>();
    TreeNode root = null;

    public TreeNode buildTree(int[] inorder, int[] postorder) {
        for (int i = 0; i < inorder.length; i++) {
            inorderPos.put(inorder[i], i);
        }
        for (int i = postorder.length - 1; i >= 0; i--) {
            insert(root, postorder[i]);
        }
        return root;
    }

    private void insert(int val) {
        if (root == null) {
            root = new TreeNode(val);
            return;
        }
        if (inorderPos.get(val) < inorderPos.get(root.val)) {
            insert(root.left, val);
        }
        if (inorderPos.get(val) > inorderPos.get(root.val)) {
            insert(root.right, val);
        }
    }
}
// @lc code=end
