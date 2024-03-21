import common.ListNode;

public class Solution206ReverseLinkedList {

    public ListNode reverseList3p(ListNode head) {
        if (head == null || head.next == null) {
            return head;
        }
        ListNode prev = head;
        ListNode current = prev.next;
        ListNode next = current == null ? null : current.next;
        prev.next = null;
        while (next != null) {
            current.next = prev;
            prev = current;
            current = next;
            next = next.next;
        }
        current.next = prev;
        return current;
    }

    public ListNode reverseList(ListNode head) {
        ListNode prev = null;
        ListNode current = head;
        while (current != null) {
            ListNode next = current.next;
            current.next = prev;
            prev = current;
            current = next;
        }
        return prev;
    }

    public static void main(String[] args) {
        ListNode n1 = new ListNode(1);
        ListNode n2 = new ListNode(2);
        ListNode n3 = new ListNode(3);
        n1.next = n2;
        n2.next = n3;
        Solution206ReverseLinkedList solution206ReverseLinkedList = new Solution206ReverseLinkedList();
        ListNode h = solution206ReverseLinkedList.reverseList(n1);
        ListNode current = h;
        while (current != null) {
            System.out.printf("%d", current.val);
            if (current.next != null) {
                System.out.print(" -> ");
            }
            current = current.next;
        }
    }

}
