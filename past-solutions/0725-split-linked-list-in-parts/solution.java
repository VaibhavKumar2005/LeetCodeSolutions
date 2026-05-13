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
    public ListNode[] splitListToParts(ListNode head, int k) {
        ListNode result[] = new ListNode[k];

        int length = 0;

        ListNode temp = head;

        while(temp != null) {
            length++;
            temp = temp.next;
        }

        int baseSize = length / k;
        int extra = length % k;

        ListNode current = head;

        for(int i = 0; i < k; i++) {

            if(current == null) {
                result[i] = null;
                continue;
            }

            result[i] = current;

            int currentSize = baseSize;

            if(extra > 0) {
                currentSize++;
                extra--;
            }

            for(int j = 1; j < currentSize; j++) {
                current = current.next;
            }

            ListNode nextPart = current.next;

            current.next = null;

            current = nextPart;
        }

        return result;
    }
}
