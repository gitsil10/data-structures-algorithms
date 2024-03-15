#imports
import unittest
from typing import Optional

#data structures
#node
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

#linked list
class LinkedList:
    def __init__(self):
        self.head = None
    def append(self, val):
        new_node = ListNode(val)
        if self.head is None:
            self.head = new_node
        else:
            current = self.head
            while current.next:
                current = current.next
            current.next = new_node
    def to_list(self):
        current = self.head
        result = []
        while current:
            result.append(current.val)
            current = current.next
        return result
    
#solution
class Solution:
    def add_two_numbers(self, l1: Optional[ListNode], l2: Optional[ListNode]) -> Optional[ListNode]:
        """
        returns the sum of two linked lists

        Args:
            l1 (Optional[ListNode]): linked list
            l2 (Optional[ListNode]): linked list

        Returns:
            Optional[ListNode]: linked list

        Notes:
            - O(n) time complexity
            - O(n) space complexity
            - Create a new linked list to store the sum of the two linked lists.
            - Iterate through the linked lists and add the values of the nodes.
            - If the sum is greater than 9, carry over the remainder to the next node.
            - If one linked list is longer than the other, append the remaining nodes to the new linked list.
        """
        result = ListNode()
        current = result
        carry = 0
        while l1 or l2:
            sum = carry
            if l1:
                sum += l1.val
                l1 = l1.next
            if l2:
                sum += l2.val
                l2 = l2.next
            carry, remainder = divmod(sum, 10)
            current.next = ListNode(remainder)
            current = current.next
        if carry:
            current.next = ListNode(carry)
        return result.next

#tests
class TestAddTwoNumbers(unittest.TestCase):
    def setUp(self):
        self.solution = Solution()
    def test_1(self):
        l1 = LinkedList()
        l1.append(2)
        l1.append(4)
        l1.append(3)
        print('l1:', l1.to_list())
        l2 = LinkedList()
        l2.append(5)
        l2.append(6)
        l2.append(4)
        print('l2:', l2.to_list())
        result = self.solution.add_two_numbers(l1.head, l2.head)
        self.assertEqual(LinkedList().head, result)
    def test_2(self):
        l1 = LinkedList()
        l1.append(0)
        l2 = LinkedList()
        l2.append(0)
        result = self.solution.add_two_numbers(l1.head, l2.head)
        self.assertEqual(LinkedList().head, result)
    def test_3(self):
        l1 = LinkedList()
        l1.append(9)
        l1.append(9)
        l1.append(9)
        l1.append(9)
        l1.append(9)
        l1.append(9)
        l1.append(9)
        l2 = LinkedList()
        l2.append(9)
        l2.append(9)
        l2.append(9)
        l2.append(9)

        result = self.solution.add_two_numbers(l1.head, l2.head)
        self.assertEqual(LinkedList().head, result)
#main
if __name__ == "__main__":
    print("running tests...")
    unittest.main()