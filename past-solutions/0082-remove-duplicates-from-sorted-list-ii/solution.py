# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def deleteDuplicates(self, head: Optional[ListNode]) -> Optional[ListNode]:
        dummy = ListNode(0)  # Dummy head before the real head
        dummy.next = head
        prev = dummy  # Pointer to the node before the current sublist

        while head:
            # If it's a duplicate node
            if head.next and head.val == head.next.val:
                duplicate_val = head.val
                # Skip all nodes with this value
                while head and head.val == duplicate_val:
                    head = head.next
                prev.next = head  # Bypass duplicates
            else:
                # No duplicate, move prev
                prev = prev.next
                head = head.next

        return dummy.next
