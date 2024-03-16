/*
Create a function that returns the sum of the two lowest positive numbers given an array of minimum 4 positive integers. 
No floats or non-positive integers will be passed.

For example, when an array is passed like [19, 5, 42, 2, 77], the output should be 7.
*/
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

long sum_two_smallest_number(size_t, const int[]);

int main(int argc, char **argv) {
    if (argc < 5) {
        printf("Incorrect number of arguments\n");
        return 1;
    }
    int numbers[argc-1];
    for (int i = 1; i < argc; i++) {
        numbers[i - 1] = strtol(argv[i], NULL, 10);
    }
    size_t n = sizeof(numbers) / sizeof(numbers[0]);
    long result = sum_two_smallest_number(argc - 1, numbers);
    printf("Result: %ld\n", result);

    return 0;
}

long sum_two_smallest_number(size_t n, const int numbers[n]) {
    int min1 = numbers[0], min2 = numbers[1];
    for (int i=2; i < n; i++) {
        if (numbers[i] < min1) {
            min2 = min1 < min2 ? min1 : min2;
            min1 = numbers[i];
        } else if (numbers[i] < min2) {
            min2 = numbers[i];
        }
    }
    
    return (long)min1 + (long)min2;
}