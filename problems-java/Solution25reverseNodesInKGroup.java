import java.util.Deque;
import java.util.LinkedList;

/**
 * @link https://leetcode.cn/problems/reverse-nodes-in-k-group/description/
 * 
 * @level hard
 * 
 * @tag linklist
 * @tag 链表
 */
public class Solution25reverseNodesInKGroup {

    /**
     * Definition for singly-linked list.
     */
    public static class ListNode {
        int val;
        ListNode next;
        ListNode() {}
        ListNode(int val) { this.val = val; }
        ListNode(int val, ListNode next) { this.val = val; this.next = next; }
    }

    public ListNode reverseKGroup(ListNode head, int k) {
        ListNode newHead = null;
        ListNode prev = null;
        Deque<ListNode> deque = new LinkedList<>();
        ListNode p = head;
        while (p != null) {
            for (int i = 0; i < k; i++) {
               deque.add(p);
                p = p.next;
                if (p == null) {
                    break;
                }
            }

            if (deque.size() < k) {
                break;
            }
            
            ListNode h = null;
            ListNode pre = null;
            ListNode c = null;
            while (!deque.isEmpty()) {
                c = deque.pollLast();
                System.out.print(c.val + ",");
                if (pre == null) {
                    pre = c;
                    h = pre;
                } else {
                    pre.next = c;
                    pre = pre.next;
                }
            }
            System.out.println();

            if (prev == null) {
                newHead = h;
            } else {
                prev.next = h;
            }
            prev = pre;
        }

        while (!deque.isEmpty()) {
            System.out.print(deque.peekFirst().val + ",");
            if (prev == null) {
                newHead = deque.pollFirst();
                prev = newHead;
            } else {
                prev.next = deque.pollFirst();
                prev = prev.next;
            }
        }
        System.out.println();

        prev.next = null;

        return newHead;
    }
}


