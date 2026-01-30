# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def detectCycle(self, head: Optional[ListNode]) -> Optional[ListNode]:
        n=0
        ptr = head
        if head == None:
            return None
        slow = head
        fast = head
        while True:
            slow = slow.next
            fast = fast.next
            if fast:
                fast = fast.next

            if fast == None or slow == None:
                break

            if fast == slow:
                slow = head
                while slow!= fast:
                    slow = slow.next
                    fast = fast.next
                
                return slow
        
        return None
        



        