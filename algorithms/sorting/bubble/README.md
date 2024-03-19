# Bubble Sort

Bubble Sort Algorithm Implementation

Swap adjacent elements if they are in wrong order.

Algorithm:
1. From first value, compare current value with next value.
2. If current is greater than next, swap.
3. If current is less than next, move to next and repeat 1.
4. Repeat 1-3 until no more swaps are needed.

Example:
    A -> [5, 4, 3, 2, 1]
    1. [4, 5, 3, 2, 1]
    2. [4, 3, 5, 2, 1]
    3. [4, 3, 2, 5, 1]
    4. [4, 3, 2, 1, 5]
    5. [3, 4, 2, 1, 5]
    6. [3, 2, 4, 1, 5]
    7. [3, 2, 1, 4, 5]
    8. [2, 3, 1, 4, 5]
    9. [2, 1, 3, 4, 5]
    10. [1, 2, 3, 4, 5]

Pseudocode:
    for i = 0 to n - 1
        for j = 0 to n - i - 1
            if arr[j] > arr[j + 1]
                swap arr[j] and arr[j + 1]

Time Complexity: O(n^2)
Space Complexity: O(1)

The algorithm is as follows:
1. Start from the first element, compare the current element with the next element of the array.
2. If the current element is greater than the next element of the array, swap them.
3. If the current element is less than the next element, move to the next element and repeat step 1.
4. Repeat steps 1-3 until no more swaps are needed.