# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def removeNthFromEnd(self, head: Optional[ListNode], n: int) -> Optional[ListNode]:
        # Create a dummy node to simplify edge cases (e.g., removing the head)
        dummy = ListNode(0, head)
        slow = dummy
        fast = dummy
        
        # Move fast pointer n + 1 steps ahead
        for _ in range(n + 1):
            fast = fast.next
        
        # Move both fast and slow until fast reaches the end
        while fast:
            slow = slow.next
            fast = fast.next
        
        # Remove the target node
        slow.next = slow.next.next
        
        # Return the new head
        return dummy.next
        
