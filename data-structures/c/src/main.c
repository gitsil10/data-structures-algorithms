#include <stdio.h>
#include <stdlib.h>
#include "../include/linked_list/linked_list.h"

#define MAX 10
int main(int argc, char **argv) {
    int arr[MAX];
    for (int i = 0; i < MAX; i++) {
        arr[i] = i;
    }
    node *lists = create_linked_list(arr, MAX);

    while (lists) {
        printf("%d ", lists->data);
        lists = lists->next;
    }

    return 0;
}