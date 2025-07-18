# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def rotateRight(self, head: Optional[ListNode], k: int) -> Optional[ListNode]:
        if not head or not head.next or k == 0:
            return head # Nothing to rotate

        # Step 1: Compute the length of the list and get the tail
        length = 1 
        tail = head
        while tail.next:
            tail = tail.next
            length +=1

        # Step 2: Calculate effective rotations needed

        k = k % length 
        if k == 0:
            return head # no rotation needed 

        # Step 3: Connect tail to head to make it circular
        tail.next = head

        # Step 4: Find the new tail : (length - k - 1) steps from head

        steps_to_new_tail = length - k
        new_tail = head
        for _ in range (steps_to_new_tail - 1):
            new_tail = new_tail.next

        # Steps 5: Set new head and break the circle
        new_head = new_tail.next
        new_tail.next = None 
        return new_head
        
