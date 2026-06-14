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
    public int pairSum(ListNode head) {
        ArrayList<Integer> arr = new ArrayList<>();

        while (head != null) {
            arr.add(head.val);
            head = head.next;
        }

        int maxTwinSum = 0;
        int n = arr.size();

        for (int i = 0; i < n / 2; i++) {
            int twinSum = arr.get(i) + arr.get(n - 1 - i);
            maxTwinSum = Math.max(maxTwinSum, twinSum);
        }

        return maxTwinSum;
    }
}
