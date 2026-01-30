# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def middleNode(self, head: Optional[ListNode]) -> Optional[ListNode]:
        n = 0
        p1 = head
        while p1 != None:
            p1 = p1.next
            n+=1
        
        cnt = n//2 
        while cnt:
            head = head.next
            cnt-=1
        return head
