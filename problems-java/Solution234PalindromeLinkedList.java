import common.ListNode;

import java.util.Stack;

public class Solution234PalindromeLinkedList {

    /**
     * stack
     * @param head
     * @return
     */
    public boolean isPalindrome(ListNode head) {
        Stack<Integer> stk = new Stack<>();
        ListNode current = head;
        do {
            stk.push(current.val);
            current = current.next;
        } while (current != null);
        current = head;
        do {
            if (!stk.pop().equals(current.val)) {
                return false;
            }
            current = current.next;
        } while (current != null);
        return true;
    }


    public static void main(String[] args) {
        ListNode n1  = new ListNode(1);
        ListNode n2  = new ListNode(2);
        ListNode n3  = new ListNode(2);
        ListNode n4  = new ListNode(1);
        n1.next = n2;
        n2.next = n3;
        n3.next = n4;
        Solution234PalindromeLinkedList solution234PalindromeLinkedList = new Solution234PalindromeLinkedList();
        System.out.println(solution234PalindromeLinkedList.isPalindrome(n1));
    }

}
