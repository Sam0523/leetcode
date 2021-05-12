/*
 * @lc app=leetcode.cn id=117 lang=java
 *
 * [117] 填充每个节点的下一个右侧节点指针 II
 */

// Definition for a Node.
class Node {
    public int val;
    public Node left;
    public Node right;
    public Node next;

    public Node() {
    }

    public Node(int _val) {
        val = _val;
    }

    public Node(int _val, Node _left, Node _right, Node _next) {
        val = _val;
        left = _left;
        right = _right;
        next = _next;
    }
};
/*
*/

// @lc code=start
class Solution {
    public Node connect(Node root) {
        for (Node head = root; head != null;) {
            head = getNextWithChildren(head);
            for (Node cur = head; cur != null;) {
                Node next = getNextWithChildren(cur.next);
                getFirstChild(cur).next = getLastChild(cur);
                getLastChild(cur).next = getFirstChild(next);
                cur = next;
            }
            head = getFirstChild(head);
        }
        return root;
    }

    private Node getNextWithChildren(Node node) {
        while (node != null) {
            if (node.left != null || node.right != null) {
                return node;
            }
            node = node.next;
        }
        return null;
    }

    private Node getFirstChild(Node node) {
        if (node == null)
            return null;
        return node.left != null ? node.left : node.right;
    }

    private Node getLastChild(Node node) {
        if (node == null)
            return null;
        return node.right != null ? node.right : node.left;
    }
}
// @lc code=end
