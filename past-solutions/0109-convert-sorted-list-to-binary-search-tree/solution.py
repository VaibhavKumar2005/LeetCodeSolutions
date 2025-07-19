# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def sortedListToBST(self, head: Optional[ListNode]) -> Optional[TreeNode]:
        # Step 1: Count the total length
        def get_length(node):
            count = 0 
            while node:
                count += 1
                node = node.next
            return count

        def build_bst(left, right):
            nonlocal head  # Needed to modify the head pointer as we go
            if left > right:
                return None

            mid = (left + right) // 2

            # Build left subtree first
            left_child = build_bst(left, mid - 1)

            # Create the root node
            root = TreeNode(head.val)
            head = head.next  # Move the list pointer forward

            # Build right subtree
            right_child = build_bst(mid + 1, right)

            root.left = left_child
            root.right = right_child
            return root

        length = get_length(head)
        return build_bst(0, length - 1)
