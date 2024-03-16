"""
Create a function that returns the sum of the two lowest positive numbers given an array of minimum 4 positive integers. 
No floats or non-positive integers will be passed.

For example, when an array is passed like [19, 5, 42, 2, 77], the output should be 7.
"""
import unittest

class Solution(unittest.TestCase):
    def __init__(self):
        super().__init__()
        
    def fn(self, numbers):
        return sum(sorted(numbers)[:2])
    def test1(self):
        self.assertEqual(self.fn([5, 8, 12, 19, 22]), 13)
    def test2(self):
        self.assertEqual(self.fn([15, 28, 4, 2, 43]), 6)
    def test3(self):
        self.assertEqual(self.fn([3, 87, 45, 12, 7]), 10)
    def test4(self):
        self.assertEqual(self.fn([23, 71, 33, 82, 1]), 24)

def main():
    sol = Solution()
    sol.test1()
    sol.test2()
    sol.test3()
    sol.test4()

if __name__ == '__main__':
    main()
    print("All tests passed")