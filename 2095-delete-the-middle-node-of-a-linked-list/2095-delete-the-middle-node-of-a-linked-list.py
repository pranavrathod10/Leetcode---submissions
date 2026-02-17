# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def deleteMiddle(self, head: Optional[ListNode]) -> Optional[ListNode]:
        slow = fast= head

        while fast and fast.next:
            slow = slow.next
            if fast.next:
                fast = fast.next.next

        temp = head
        if not temp.next:
            return None
            
        while temp.next != slow:
            temp = temp.next

        temp.next = slow.next
        
        return head