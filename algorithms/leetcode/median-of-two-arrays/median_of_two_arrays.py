"""
Pseudocode:
    1. Merge the two arrays
    2. Sort the merged array
    3. If the length of the merged array is even, return the average of the two middle elements
    4. If the length of the merged array is odd, return the middle element

    C <- A + B
    sort(C)
    loc <- floor(|C|/2)
    
    if mod(|C|, 2) == 0:
        return (C[loc] + C[loc - 1]) / 2
    else:
        return C[loc]

Time complexity:
    O(nlogn) where n is the total number of elements in the two arrays

Space complexity:
    O(n) where n is the total number of elements in the two arrays
"""
import unittest, sys
class Solution(unittest.TestCase):
    def self_soln(self, nums1: list[int], nums2: list[int]) -> float:
        """
        Given two sorted arrays nums1 and nums2 of size m and n respectively, return the median of the two sorted arrays.

        Args:
            nums1 (list): the first sorted array
            nums2 (list): the second sorted array

        Return:
            float: the median of the two sorted arrays
        
        Time complexity:
            O(nlogn) where n is the total number of elements in the two arrays

        Space complexity:
            O(n) where n is the total number of elements in the two arrays
        """
        #merge and re-sort
        nums = nums1 + nums2
        nums.sort()
        
        #length of array
        n = len(nums)
        i = n//2

        #even
        if n % 2 == 0:
            return(nums[i] + nums[i - 1]) / 2
        else:
            return nums[i]
    def test_1(self):
        self.assertEqual(self.self_soln([1,3], [2]), 2.0)
    def test_2(self):
        self.assertEqual(self.self_soln([1,2], [3,4]), 2.5)
    def test_3(self):
        self.assertEqual(self.self_soln([0,0], [0,0]), 0.0)
    def test_4(self):
        self.assertEqual(self.self_soln([], [1]), 1.0)

if __name__ == "__main__":
    unittest.main()
        