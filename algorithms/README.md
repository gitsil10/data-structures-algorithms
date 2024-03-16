sf

# Data Structures and Algorithms

Collection of solutions to data structures and algorithm problem sets.

## Data Structures
Collection of objects and their operations.

### Array

### Linked List

### Stack

### Queue

### Tree

### Graph

### Hash Table

## Codewars

### Sum of two lowest positive integer
Returns the sum of the two lowest positive integers in an array of minimum length 4.
  
  time -> O(n)
  space -> O(1)
  a <- A[0]
  b <- A[1]
  
  for i -> n:
    if A[n] < a:
      if b > a:
        b <- a
      a <- A[n]
    else if A[n] < b:
      b <- A[n]
  return a+b

  - C implementation
  
