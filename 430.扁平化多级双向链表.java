/*
 * @lc app=leetcode.cn id=430 lang=java
 *
 * [430] 扁平化多级双向链表
 */

// Definition for a Node.
class Node {
    public int val;
    public Node prev;
    public Node next;
    public Node child;
};

// @lc code=start

class Solution {
    public Node flatten(Node head) {
        return flattenImpl(head).head;
    }

    private class DualLinkedList {

        public Node head, tail;

        public DualLinkedList(Node _head, Node _tail) {
            head = _head;
            tail = _tail;
        }
    }

    private DualLinkedList flattenImpl(Node head) {
        Node ptr = head, tail = head;
        while (ptr != null) {
            if (ptr.child != null) {
                DualLinkedList flattenChild = flattenImpl(ptr.child);
                ptr.child = null;
                if (ptr.next != null) {
                    flattenChild.tail.next = ptr.next;
                    ptr.next.prev = flattenChild.tail;
                }
                ptr.next = flattenChild.head;
                flattenChild.head.prev = ptr;
                tail = flattenChild.tail;
                ptr = flattenChild.tail.next;
            } else {
                tail = ptr;
                ptr = ptr.next;
            }
        }
        return new DualLinkedList(head, tail);
    }
}
// @lc code=end
