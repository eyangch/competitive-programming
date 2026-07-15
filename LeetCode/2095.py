# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def deleteMiddle(self, head: Optional[ListNode]) -> Optional[ListNode]:
        ll_len = 0
        ptr = head
        while ptr is not None:
            ptr = ptr.next
            ll_len += 1
        
        to_del_p = None
        to_del = head
        for _ in range(ll_len // 2):
            to_del_p = to_del
            to_del = to_del.next
        
        if to_del_p is not None:
            to_del_p.next = to_del.next
        else:
            head = head.next
        
        return head

        