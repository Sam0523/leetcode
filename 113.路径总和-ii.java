import java.util.LinkedList;
import java.util.List;

/*
 * @lc app=leetcode.cn id=113 lang=java
 *
 * [113] 路径总和 II
 */
// @lc code=start
class Solution {
    public List<List<Integer>> pathSum(TreeNode root, int targetSum) {
        List<List<Integer>> ret = new LinkedList<>();
        if (root == null) {
            return ret;
        }
        if (root.left == null && root.right == null) {
            if (root.val == targetSum) {
                LinkedList<Integer> list = new LinkedList<Integer>();
                list.add(root.val);
                ret.add(list);
            }
            return ret;
        }
        ret.addAll(pathSum(root.left, targetSum - root.val));
        ret.addAll(pathSum(root.right, targetSum - root.val));
        ret.replaceAll(list -> {
            list.add(0, root.val);
            return list;
        });
        return ret;
    }
}
// @lc code=end
