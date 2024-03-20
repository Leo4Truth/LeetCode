import common.ListNode;

public class Solution1669MergeInBetweenLinkedLists {
    public ListNode mergeInBetween(ListNode list1, int a, int b, ListNode list2) {
        ListNode p1 = list1;
        for (int i = 1; i < a; i++) {
            p1 = p1.next;
        }
        System.out.println("p1: " + String.valueOf(p1.val));

        ListNode p2 = p1;
        for (int i = a; i <= b + 1; i++) {
            p2 = p2.next;
        }
        System.out.println("p2: " + String.valueOf(p2.val));

        ListNode list2Tail = list2;
        while (list2Tail.next != null) {
            list2Tail = list2Tail.next;
        }

        System.out.println("list2Tail: " + String.valueOf(list2Tail.val));

        p1.next = list2;
        list2Tail.next = p2;
        return list1;
    }

    public static void main(String[] args) {
        ListNode current = null;

        ListNode list1 = new ListNode(10);
        current = list1;
        current.next = new ListNode(1);
        current = current.next;
        current.next = new ListNode(13);
        current = current.next;
        current.next = new ListNode(6);
        current = current.next;
        current.next = new ListNode(9);
        current = current.next;
        current.next = new ListNode(5);

        ListNode list2 = new ListNode(1000000);
        current = list2;
        current.next = new ListNode(1000001);
        current = current.next;
        current.next = new ListNode(1000002);

        Solution1669MergeInBetweenLinkedLists solution1669MergeInBetweenLinkedLists = new Solution1669MergeInBetweenLinkedLists();
        ListNode list = solution1669MergeInBetweenLinkedLists.mergeInBetween(list1, 3, 4, list2);

        current = list;
        System.out.print("[");
        while (current.next != null) {
            System.out.print(current.val);
            System.out.print(",");
            current = current.next;
        }
        System.out.print(current.val);
        System.out.print("]");
    }
}
