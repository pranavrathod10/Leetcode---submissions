# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def hasCycle(self, head: Optional[ListNode]) -> bool:
        fast = head
        slow = head
        if head == None:
            return False
        while True:
            slow = slow.next
            fast = fast.next
            if fast:
                fast = fast.next

            if(slow == None or fast == None):
                break

            if(fast == slow):
                return True

            
        
        return False


        