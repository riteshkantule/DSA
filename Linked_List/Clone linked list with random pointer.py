"""
# Definition for a Node.
class Node:
    def __init__(self, x: int, next: 'Node' = None, random: 'Node' = None):
        self.val = int(x)
        self.next = next
        self.random = random
"""

# Hashmap O(N) extra space 
class Solution:
    def copyRandomList(self, head: "Optional[Node]") -> "Optional[Node]":
        if head is None:
            return None

        old_to_new = {} # hash map --> O(N)extra

        current = head
        while current:
            old_to_new[current] = Node(current.val)
            current = current.next

        current = head
        while current:
            if current.next:
                old_to_new[current].next = old_to_new[current.next]
            if current.random:
                old_to_new[current].random = old_to_new[current.random]
            current = current.next

        return old_to_new[head]


# Best approach 

"""
# Definition for a Node.
class Node:
    def __init__(self, x: int, next: 'Node' = None, random: 'Node' = None):
        self.val = int(x)
        self.next = next
        self.random = random
"""


class Solution:
    def copyRandomList(self, head: "Optional[Node]") -> "Optional[Node]":
        
        if not head:
            return None
        
        temp = head

        while temp:
            new_Node = Node(temp.val)
            new_Node.next = temp.next
            temp.next = new_Node

            temp = temp.next.next
        
        temp = head

        while temp:
            new_Node = temp.next
            if temp.random is not None:
                new_Node.random = temp.random.next
            else:
                new_Node.random = None
            temp = temp.next.next

        curr = head

        dummy = Node(-1)
        dummy.next = curr.next
        res = dummy

        while curr:
            res.next = curr.next
            curr.next = curr.next.next
            
            curr = curr.next
            res = res.next
        
        return dummy.next


