SF

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

  Input
  -----
  Array A of length N of positive integers
  N > 3
  ------------------------------------------------------------------------------------  
  time -> O(n)
  space -> O(1)
  
  start
  
  a <- A[0]
  b <- A[1]
    
  for i <- 2 to N:
    if A[i] < a:
      if b > a:
        b <- a
      a <- A[i]
  
    else if A[i] < b:
      b <- A[i]
  
  return a+b
  
  - C implementation  
------------
  time -> O(1)
  space -> O(1)
  
  sort(A)
  return A[0] + A[1]
  
  - Python implementation
    
