#imports
import unittest
#solution
class Solution(unittest.TestCase):
    #implementations
    def stray(self, arr:list[int]) -> int:
        """
        Finds the unique value of a list

        Args:
            arr (list[int]): list of integers

        Returns:
            int: unique value of the list

        Details:
            if the list does not contain a unique value, the function returns -1
            time complexity: O(n)
            space complexity: O(n)
            
        Example:
            stray([1, 1, 2]) -> 2
            stray([17, 17, 3, 17, 17, 17, 17]) -> 3
            stray([8, 1, 1, 1, 1, 1, 1]) -> 8
            stray([1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1]) -> -1
            stray([1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 13]) -> 13
        """
        arr = [x for x in arr if arr.count(x) == 1]
        return arr[0] if len(arr) > 0 else -1
    
    #tests
    def test_1(self):
        self.assertEqual(self.stray([1, 1, 2]), 2)

    def test_2(self):
        self.assertEqual(self.stray([17, 17, 3, 17, 17, 17, 17]), 3)

    def test_3(self):
        self.assertEqual(self.stray([8, 1, 1, 1, 1, 1, 1]), 8)

    def test_4(self):
        self.assertEqual(self.stray([1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 13]), 13)

    def test_5(self):
        self.assertNotEqual(self.stray([1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1]), 1)

#tests
if __name__ == "__main__":
    unittest.main()