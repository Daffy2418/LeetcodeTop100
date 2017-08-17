# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None

from heapq import *

class Solution(object):
    def mergeKLists(self, lists):
        heap=[]
        head=ListNode(-1);p=head
        for node in lists:
            if node:
                heappush(heap,(node.val,node))
        while heap:
            smallest=heappop(heap)[1]
            p.next=smallest
            p=smallest
            if smallest.next:
                heappush(heap,(smallest.next.val,smallest.next))
        return head.next
