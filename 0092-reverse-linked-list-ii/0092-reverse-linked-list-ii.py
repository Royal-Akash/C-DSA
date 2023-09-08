# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution(object):
    def reverseBetween(self, head, m, n):
        """
        :type head: ListNode
        :type m: int
        :type n: int
        :rtype: ListNode
        """
        dummy = ListNode(0)
        dummy.next = head
        pre = dummy

        for _ in range(m - 1):
            pre = pre.next

        cur = pre.next

        for _ in range(n - m):
            temp = pre.next
            pre.next = cur.next
            cur.next = cur.next.next
            pre.next.next = temp

        return dummy.next
