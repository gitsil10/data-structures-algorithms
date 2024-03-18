/*
SF
Codewars: Find Stray Number

Given an odd-length array of integers
Find the single different number
*/
#include <stdio.h>
#include <stdlib.h>

int stray(size_t n, int arr[n]);
int stray_2(size_t n, int arr[n]);

int main(int argc, char **argv) {
    if (argc < 2) {
        printf("Usage: %s\n", argv[0]);
        return 1;
    }
    int n = argc - 1, arr[n];

    for (int i = 0; i < n; i++) {
        arr[i] = strtol(argv[i + 1], NULL, 10);
    }
    int results[] = {stray(n, arr), stray_2(n, arr)},
        n_results = sizeof(results) / sizeof(results[0]);
    
    for (int i = 0; i < n_results; i++) {
        printf("result %d: %d\n", i, results[i]);
    }

    return 0;
}

int stray(size_t n, int arr[n]) {
    /*
    @brief find the single different number in an array
    @param n: size of the array
    @param arr: array of integers
    @return the single different number

    @example
    n = 1
    arr = [1]
    result = 1

    n = 3
    arr = [1, 1, 2]
    result = 2

    @note
    time: O(n^2)
    space: O(n)
    inefficient implementation

    @details
    1. create a new array arr2 with the same elements as arr
    2. iterate through arr2
        1. count the number of times the current element appears in arr
        2. if the count is 1, return the current element
    3. free arr2
    4. return result
    */
    int i, j, k, count, result=0, *arr2;
    arr2 = (int *)malloc(n * sizeof(int));

    for (i = 0; i < n; i++) {
        arr2[i] = arr[i];
    }
    for (i = 0; i < n; i++) {
        count = 0;
        for (j = 0; j < n; j++) {
            if (arr2[i] == arr[j]) {
                count++;
            }
        }
        if (count == 1) {
            result = arr2[i];
            break;
        }
    }
    free(arr2);
    return result;
}

int stray_2(size_t n, int arr[n]) {
    /*
    @brief find the single different number in an array
    @param n: size of the array
    @param arr: array of integers
    @return the single different number

    @example
    n = 1
    arr = [1]
    result = 1

    n = 3
    arr = [1, 1, 2]
    result = 2

    @note
    time: O(n)
    space: O(1)
    flawed implementation but more efficient than stray

    @details
    1. iterate through arr
        1. XOR the current element with the result
    2. return result

    @bug
    1. assumes that the array has an odd length
    2. assumes that each element appears an even number of times except for one
    */
    int res = 0;
    for (size_t i = 0; i < n; i++) res ^= arr[i];
    return res;
}