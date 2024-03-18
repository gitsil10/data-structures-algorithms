/*
SF

Codewars: Don't give me five!
Count the number of integers that do not contain the digit 5
*/
#include <stdio.h>
#include <stdlib.h>

int dont_give_me_five(int start, int end);
int dont_give_me_five_2(int start, int end);

int main(int argc, char **argv) {
    if (argc < 3) {
        printf("Usage: %s\n", argv[0]);
        return 1;
    }
    int start = strtol(argv[1], NULL, 10),
        end = strtol(argv[2], NULL, 10);
    int result = dont_give_me_five(start, end);
    printf("result: %d\n", result);

    return 0;
}

int dont_give_me_five(int start, int end) {
    /*
    @brief count the number of integers that do not contain the digit 5
    @param start: start of the range
    @param end: end of the range
    @return the number of integers that do not contain the digit 5

    @example
    start = 1
    end = 9
    result = 8

    start = 4
    end = 8
    result = 5

    @note
    time: O(n)
    space: O(1)
    */
    int count = 0;
    for (int i = start; i <= end; i++) {
        int n = abs(i), five = 0;
        while (n > 0) {
            if (n % 10 == 5) {
                five = 1;
                break;
            }
            n /= 10;
        }
        if (!five)
            count++;
    }
    return count;
}
int dont_give_me_five_2(int start, int end) {
    /*
    @brief count the number of integers that do not contain the digit 5
    @param start: start of the range
    @param end: end of the range
    @return the number of integers that do not contain the digit 5

    @example
    start = 1
    end = 9
    result = 8

    start = 4
    end = 8
    result = 5

    @note
    time: O(n)
    space: O(1)
    */
    char *buf = malloc(11);
    int count = 0;
    for(int i = start; i <= end; i++) {
        sprintf(buf, "%d", i);
        if( strchr(buf, '5') == NULL ) count++;
    }
    return count;
}