/*
SF
Dependencies:
    - stdio.h
    - stdlib.h
    - string.h

Usage:
    $ ./bubble_sort <number of elements> <c|d|i> <elements...>
    $ ./bubble_sort 5 c a b c d e
    $ ./bubble_sort 5 d 1.1 2.2 3.3 4.4 5.5
    $ ./bubble_sort 5 i 5 4 3 2 1

Arguments:
    number of elements: the number of elements to sort
    c: sort characters
    d: sort decimals
    i: sort integers
    elements: the elements to sort
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void bubble_sort(size_t n, void *array, size_t size, int (*cmp)(const void *, const void *));
int compare_ints(const void *a, const void *b);
int compare_chars(const void *a, const void *b);
int compare_decimal(const void *a, const void *b);
void sort_chars(size_t n, char **array);
void sort_decimals(size_t n, char **array);
void sort_ints(size_t n, char **array);

int main(int argc, char **argv) {
    //input validation
    if (argc < 3) {
        printf("Usage: %s <number of elements>\n", argv[0]);
        return 1;
    }

    printf("Bubble Sort Algorithm Implementation\n");
    size_t n = argc - 2;
    const int type = strtol(argv[1], NULL, 10);

    //run based on input type
    switch(argv[1][0]) {
        //character
        case 'c': {
            sort_chars(n, argv);
            break;
        }
        //double
        case 'd': {
            sort_decimals(n, argv);
            break;
        }
        //integer
        case 'i': {
            sort_ints(n, argv);
            break;
        }
        default:
            printf("Usage: %s <number of elements> <c|d|i>\n", argv[0]);
            return 1;
    }
    
    return 0;
}

void bubble_sort(size_t n, void *array, size_t size, int (*cmp)(const void *, const void *)) {
    /*
    @brief sort an array using the bubble sort algorithm
    @param n: size of the array
    @param arry: array of elements
    @return void

    @example
    n = 5
    array = [5, 4, 3, 2, 1]
    bubble_sort(n, array, sizeof(int), compare_ints)
    array = [1, 2, 3, 4, 5]

    @note
    time: O(n^2)
    space: O(1)
    inefficient implementation

    @details
    1. iterate through the array
        1. iterate through the array
            1. if the current element is greater than the next element, swap them
    */
    for (size_t i = 0; i < n - 1; i++) {
        for (size_t j = 0; j < n - i - 1; j++) {
            if (cmp(array + j * size, array + (j + 1) * size) > 0) {
                void *temp = malloc(size);
                memcpy(temp, array + j * size, size);
                memcpy(array + j * size, array + (j + 1) * size, size);
                memcpy(array + (j + 1) * size, temp, size);
                free(temp);
            }
        }
    }
}

int compare_ints(const void *a, const void *b) {
    /*
    @brief compare two integers
    @param a: first integer
    @param b: second integer
    @return 1 if a > b, -1 if a < b, 0 if a == b

    @example
    a = 1
    b = 2
    result = -1

    @note
    time: O(1)
    space: O(1)

    @details
    1. if a > b, return 1
    2. if a < b, return -1
    3. return 0
    */
    int x = *(const int*)a, y = *(const int*)b;
    return x > y ? 1 : x < y ? -1 : 0;
}
int compare_chars(const void *a, const void *b) {
    /*
    @brief compare two characters
    @param a: first character
    @param b: second character
    @return 1 if a > b, -1 if a < b, 0 if a == b

    @example
    a = 'a'
    b = 'b'
    result = -1

    @note
    time: O(1)
    space: O(1)

    @details
    1. if a > b, return 1
    2. if a < b, return -1
    3. return 0
    */
    char x = *(const char*)a, y = *(const char*)b;
    return x > y ? 1 : x < y ? -1 : 0;
}
int compare_decimal(const void *a, const void *b) {
    /*
    @brief compare two decimals
    @param a: first decimal
    @param b: second decimal
    @return 1 if a > b, -1 if a < b, 0 if a == b

    @example
    a = 1.1
    b = 2.2
    result = -1

    @note
    time: O(1)
    space: O(1)

    @details
    1. if a > b, return 1
    2. if a < b, return -1
    3. return 0
    */
    double x = *(const double*)a, y = *(const double*)b;
    return x > y ? 1 : x < y ? -1 : 0;
}
void sort_chars(size_t n, char **array) {
    /*
    @brief sort an array of characters
    @param n: size of the array
    @param array: array of characters
    @return void

    @example
    n = 5
    array = ['e', 'd', 'c', 'b', 'a']
    sort_chars(n, array)
    array = ['a', 'b', 'c', 'd', 'e']
    */
    char chars[n];
    for (size_t i = 0; i < n; i++) {
        chars[i] = array[i + 2][0];
    }
    char *p_chars = chars;

    printf("Original chars ->\t");
    for (size_t i = 0; i < n; i++) {
        printf("%c ", chars[i]);
    }
    bubble_sort(n, &chars, sizeof(char), compare_chars);

    printf("\nSorted chars ->\t");
    for (size_t i = 0; i < n; i++) {
        printf("%c ", chars[i]);
    }
}
void sort_decimals(size_t n, char **array) {
    /*
    @brief sort an array of decimals
    @param n: size of the array
    @param array: array of decimals
    @return void

    @example
    n = 5
    array = [5.5, 4.4, 3.3, 2.2, 1.1]
    sort_decimals(n, array)
    array = [1.1, 2.2, 3.3, 4.4, 5.5]
    */
    double decimals[n];
    for (size_t i = 0; i < n; i++) {
        decimals[i] = strtod(array[i + 2], NULL);
    }
    double *p_decimals = decimals;

    printf("Original decimals ->\t");
    for (size_t i = 0; i < n; i++) {
        printf("%.2lf ", decimals[i]);
    }

    bubble_sort(n, &decimals, sizeof(double), compare_decimal);

    printf("\nSorted decimals ->\t");
    for (size_t i = 0; i < n; i++) {
        printf("%.2lf ", decimals[i]);
    }
}
void sort_ints(size_t n, char **array) {
    /*
    @brief sort an array of integers
    @param n: size of the array
    @param array: array of integers
    @return void

    @example
    n = 5
    array = [5, 4, 3, 2, 1]
    sort_ints(n, array)
    array = [1, 2, 3, 4, 5]
    */
    int ints[n];
    for (size_t i = 0; i < n; i++) {
        ints[i] = strtol(array[i + 2], NULL, 10);
    }
    int *p_ints = ints;

    printf("Original array ->\t");
    for (size_t i = 0; i < n; i++) {
        printf("%d ", ints[i]);
    }
    bubble_sort(n, &ints, sizeof(int), compare_ints);

    printf("\nSorted ints ->\t");
    for (size_t i = 0; i < n; i++) {
        printf("%d ", ints[i]);
    }
}
