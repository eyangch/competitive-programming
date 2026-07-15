# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def sortList(self, head: Optional[ListNode]) -> Optional[ListNode]:
        if head == None:
            return None
        L = []
        while head != None:
            L.append(head.val)
            head = head.next
        L.sort()
        ans = ListNode(L[0])
        tail = ans
        for i in range(1, len(L)):
            tail.next = ListNode(L[i])
            tail = tail.next
        return ans