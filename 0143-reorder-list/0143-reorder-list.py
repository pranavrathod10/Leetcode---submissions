# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def reverse(self, head: Optional[ListNode]) -> ListNode:
        p1 = None
        p2 = head
        if p2:
            p3 = p2.next
        
        while p2:
            p2.next = p1
            p1 = p2
            p2 = p3
            if p3:
                p3 = p3.next

        
        return p1

    def mergeLL(self, first: Optional[ListNode], second: Optional[ListNode]) -> None:

        while first and second:
            fnext = first.next
            first.next = second

            secnext = second.next
            second.next = fnext

            first, second = fnext, secnext

    def reorderList(self, head: Optional[ListNode]) -> None:
        """
        Do not return anything, modify head in-place instead.
        """
        # find middle
        slow = fast = head
        while fast and fast.next:
            slow = slow.next
            fast = fast.next.next

        mid  = slow
        
        first = head
        second = mid.next
        mid.next = None

        second = self.reverse(second)
        print(first)
        print(second)
        self.mergeLL(first,second)

        return


