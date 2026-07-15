# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def pairSum(self, head: Optional[ListNode]) -> int:
        a = []
        while head is not None:
            a.append(head.val)
            head = head.next
        return max(a[i] + a[len(a)-1-i] for i in range(len(a)//2))