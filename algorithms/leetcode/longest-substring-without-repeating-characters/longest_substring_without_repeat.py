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
    def self_soln(self, s: str) -> int:
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
    
    def user_soln_1(self, s: str) -> int:
        left = max_length = 0
        char_set = set()

        for right in range(len(s)):
            while s[right] in char_set:
                char_set.remove(s[left])
                left += 1
            char_set.add(s[right])
            max_length = max(max_length, right - left + 1)
        return max_length
    
    def user_soln_2(self, s:str) -> int:
        max_length = 0
        left = 0
        last_seen = {}

        for right, c in enumerate(s):
            if c in last_seen and last_seen[c] >= left:
                left = last_seen[c] + 1
            last_seen[c] = right
            max_length = max(max_length, right - left + 1)
        return max_length
    
    def test_1(self):
        self.assertEqual(self.self_soln("abcabcbb"), 3)
        self.assertEqual(self.user_soln_1("abcabcbb"), 3)
        self.assertEqual(self.user_soln_2("abcabcbb"), 3)

    def test_2(self):
        self.assertEqual(self.self_soln("bbbbb"), 1)
        self.assertEqual(self.user_soln_1("bbbbb"), 1)
        self.assertEqual(self.user_soln_2("bbbbb"), 1)

    def test_3(self):
        self.assertEqual(self.self_soln("pwwkew"), 3)
        self.assertEqual(self.user_soln_1("pwwkew"), 3)
        self.assertEqual(self.user_soln_2("pwwkew"), 3)

    def test_4(self):
        self.assertEqual(self.self_soln(""), 0)
        self.assertEqual(self.user_soln_1(""), 0)
        self.assertEqual(self.user_soln_2(""), 0)

    def test_5(self):
        self.assertEqual(self.self_soln(" "), 1)
        self.assertEqual(self.user_soln_1(" "), 1)
        self.assertEqual(self.user_soln_2(" "), 1)

    def test_6(self):
        self.assertEqual(self.self_soln("au"), 2)
        self.assertEqual(self.user_soln_1("au"), 2)
        self.assertEqual(self.user_soln_2("au"), 2)

    def test_7(self):
        self.assertEqual(self.self_soln("dvdf"), 3)
        self.assertEqual(self.user_soln_1("dvdf"), 3)
        self.assertEqual(self.user_soln_2("dvdf"), 3)
    
    
if __name__ == "__main__":
    unittest.main()
    
    
