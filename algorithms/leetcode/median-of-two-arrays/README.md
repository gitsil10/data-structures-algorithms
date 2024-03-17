# Median of Two Sorted Arrays
Find the median of two sorted arrays

## Pseudocode
    1. Merge the two arrays
    2. Sort the merged array
    3. If the length of the merged array is even, return the average of the two middle elements
    4. If the length of the merged array is odd, return the middle element

### Brute Force / Direct
    C <- A + B
    sort(C)
    loc <- floor(|C|/2)
    
    if mod(|C|, 2) == 0:
        return (C[loc] + C[loc - 1]) / 2
    else:
        return C[loc]

    Time: O(nlogn) where n is the total number of elements in the two arrays
    Space: O(n) where n is the total number of elements in the two arrays

### Binary Search
    low <- 0
    high <- len(C) - 1

    while low <= high:
        mid <- (low + high) // 2
        left_max <- float('-inf') if mid == 0 else C[mid - 1]
        right_min <- float('inf') if mid == len(C) else C[mid]
        
        if left_max <= right_min:
            if (len(C) + len(D)) % 2 == 0:
                return (left_max + right_min) / 2
            else:
                return right_min
        elif left_max > right_min:
            high <- mid - 1
        else:
            low <- mid + 1
    return 0
    
    Time: O(logn)
    Space: O(1)