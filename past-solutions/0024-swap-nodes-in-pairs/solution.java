/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */

class Solution {

    public ListNode swapPairs(ListNode head) {
        
        // Edge case: empty list or single node
        if (head == null || head.next == null) {
            return head;
        }

        // Create a dummy node to simplify swapping at head
        ListNode dummy = new ListNode(0);
        dummy.next = head;

        // prev pointer helps connect previous part to swapped pair
        ListNode prev = dummy;

        // Loop while there are at least two nodes to swap
        while (prev.next != null && prev.next.next != null) {

            ListNode first = prev.next;        // First node of the pair
            ListNode second = first.next;     // Second node of the pair

            // Swapping nodes
            first.next = second.next;
            second.next = first;
            prev.next = second;

            // Move prev pointer to the end of swapped pair
            prev = first;
        }

        // Return new head
        return dummy.next;
    }
}
