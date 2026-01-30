# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def reverseList(self, head: Optional[ListNode]) -> Optional[ListNode]:
        p1 = None
        p2 = head
        if p2 == None:
            return p2
        p3 = p2.next
        if p3 == None:
            return head
        while p2 != None:
            p2.next = p1
            p1 = p2
            p2 = p3
            if p3:
                p3 = p3.next
            # p1 = 
        return p1