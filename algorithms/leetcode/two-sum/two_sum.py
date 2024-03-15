#imports
import unittest

#solution
class Solution:
    #inefficient
    def two_sum_loop(self, nums: list[int], target: int) -> list[int]:
        """
        returns indices of two numbers from the list that add up to the target

        Args:
            nums (list[int]): list of integers
            target (int): target integer

        Returns:
            list[int]: list of indices of two numbers that add up to the target

        Notes:
            - O(n^2) time complexity
            - O(1) space complexity
            - The outer loop iterates through each element of the list.
            - The inner loop iterates through each element of the list after the current element.
            - If the sum of the current element and the inner loop element is equal to the target, return the indices of the two elements.
            - If no two elements add up to the target, return an empty list.
        """
        for i in range(len(nums)):
            for j in range(i+1, len(nums)):
                if nums[i] + nums[j] == target:
                    return [i, j]
        return []
    #efficient
    def two_sum_hash(self, nums: list[int], target: int) -> list[int]:
        """
        returns indices of two numbers from the list that add up to the target

        Args:
            nums (list[int]): list of integers
            target (int): target integer

        Returns:
            list[int]: list of indices of two numbers that add up to the target

        Notes:
            - O(n) time complexity
            - O(n) space complexity
            - Create a hash table to store the elements of the list and their indices.
            - Iterate through the list and check if the complement of the current element is in the hash table.
            - If the complement is in the hash table, return the indices of the current element and the complement.
            - If no two elements add up to the target, return an empty list.
        """
        hash_table = {}
        for i, num in enumerate(nums):
            complement = target - num
            if complement in hash_table:
                return [hash_table[complement], i]
            hash_table[num] = i
        return []
    
#tests
class TestTwoSum(unittest.TestCase):
    def setUp(self):
        self.solution = Solution()
    def test_1(self):
        nums = [2, 7, 11, 15]
        target = 9
        self.assertEqual(self.solution.two_sum_loop(nums, target), [0, 1])
        self.assertEqual(self.solution.two_sum_hash(nums, target), [0, 1])
    def test_2(self):
        nums = [3, 2, 4]
        target = 6
        self.assertEqual(self.solution.two_sum_loop(nums, target), [1, 2])
        self.assertEqual(self.solution.two_sum_hash(nums, target), [1, 2])
    def test_3(self):
        nums = [3, 3]
        target = 6
        self.assertEqual(self.solution.two_sum_loop(nums, target), [0, 1])
        self.assertEqual(self.solution.two_sum_hash(nums, target), [0, 1])
    def test_4(self):
        nums = [3, 2, 4]
        target = 8
        self.assertEqual(self.solution.two_sum_loop(nums, target), [])
        self.assertEqual(self.solution.two_sum_hash(nums, target), [])
    def test_5(self):
        nums = [3, 2, 4]
        target = 7
        self.assertEqual(self.solution.two_sum_loop(nums, target), [0, 2])
        self.assertEqual(self.solution.two_sum_hash(nums, target), [0, 2])
    def test_6(self):
        nums = [3, 2, 4]
        target = 5
        self.assertEqual(self.solution.two_sum_loop(nums, target), [0, 1])
        self.assertEqual(self.solution.two_sum_hash(nums, target), [0, 1])
#run
if __name__ == "__main__":
    print("running tests...")
    unittest.main()