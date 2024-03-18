class Solution:
    def dont_give_me_five(self, start:int, end:int) -> int:
        """
        count the number of integers that do not contain the digit 5

        Args:
            start (int): start of the range
            end (int): end of the range

        Returns:
            int: number of integers that do not contain the digit 5
        """
        return sum('5' not in str(i) for i in range(start, end+1))
    
    def dont_give_me_five_2(self, start:int, end:int) -> int:
        """
        count the number of integers that do not contain the digit 5

        Args:
            start (int): start of the range
            end (int): end of the range

        Returns:
            int: number of integers that do not contain the digit 5
        """
        count = 0
        for i in range(start, end+1):
            if '5' not in str(i):
                count += 1
        return count