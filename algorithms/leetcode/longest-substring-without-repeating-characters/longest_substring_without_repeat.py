"""
Given a string s, find the length of the longest substring without repeating characters.

Example 1:
    Input: s = "abcabcbb"
    Output: 3
    Explanation: The answer is "abc", with the length of 3.

Example 2:
    Input: s = "bbbbb"
    Output: 1
    Explanation: The answer is "b", with the length of 1.

Constraints:
    0 <= s.length <= 5 * 10^4
    s (str): english letters, digits, symbols, and spaces
"""
#import
import unittest
#solution
class Solution(unittest.TestCase):
    def self_sol(self, s: str) -> int:
        """
        Given a string s, find the length of the longest substring without repeating characters.


        Pseudocode:
            if |string| in {0,1} 
                return |string|
            else
                string_size <- 0
                string_start <- 0
                string_end <- 0
                while string_end < |string|
                    if s[string_end] is not in string from start to end then
                        string_end <- n + 1
                        string_size <- max of string_size and (string_end - string_start)
                    else
                        string_start <- string_start + 1
                return string_size

        time complexity -> O(n)
        space complexity -> O(1)

        Args:
            s (str): input string

        Returns:
            int: length of longest substring without repeating characters
        """
        if len(s) in (0,1):
            return len(s)
        
        length = 0
        i = 0
        n = 0
        while n < len(s):
            if s[n] not in s[i:n]:
                n += 1
                length = max(length, n - i)
            else:
                i += 1
        return length
    
    def test_1(self):
        self.assertEqual(self.lengthOfLongestSubstring("abcabcbb"), 3)

    def test_2(self):
        self.assertEqual(self.lengthOfLongestSubstring("bbbbb"), 1)

    def test_3(self):
        self.assertEqual(self.lengthOfLongestSubstring("pwwkew"), 3)

if __name__ == "__main__":
    unittest.main()
    
    
