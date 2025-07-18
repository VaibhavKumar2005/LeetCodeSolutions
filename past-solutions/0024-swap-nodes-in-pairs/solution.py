# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def swapPairs(self, head: Optional[ListNode]) -> Optional[ListNode]:
        dummy = ListNode(0)
        dummy.next = head
        previous = dummy

        while head and head.next:
            first = head
            second = head.next

            # Swapping
            previous.next = second
            first.next = second.next
            second.next = first

            # Move pointers
            previous = first
            head = first.next

        return dummy.next 

        
