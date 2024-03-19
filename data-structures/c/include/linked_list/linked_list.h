/*
@gitsil10
S Flores
2024-03

@title
Linked List

@brief
Linked list header file

@note
time: O(n)
space: O(n)

@details
linked list header file
node -> struct | integer data | pointer to the next node
create -> creates a new node with the given data
insert -> inserts a new node with the given data at the head of the list
append -> appends a new node with the given data at the end of the list
delete -> deletes the first node with the given data
print -> prints the list | output
free -> frees the list | clear memory
*/
#include <stdio.h>
#include <stdlib.h>

#ifndef LINKED_LIST_H
#define LINKED_LIST_H

//data
typedef struct node {
    /*
    @brief node struct
    @details
    integer data
    pointer to the next node

    @note
    space: O(1)
    */
    int data;
    struct node *next;
} node;

//prototypes
node *create_node(int data);
node *insert_node(node *head, int data);
node *append_node(node *head, int data);
node *delete_node(node *head, int data);
void print_list(node *head);
void free_list(node *head);

//definitions
node *create_linked_list(int *arr, int n) {
    /*
    @brief create a linked list
    @param arr integer pointer
    @param n integer
    @return node pointer

    @details
    creates a linked list from the given array

    @note
    time: O(n)
    space: O(n)
    */
    node *head = NULL;
    for (int i = n - 1; i >= 0; i--) {
        head = insert_node(head, arr[i]);
    }
    return head;
}
node *create_node(int data) {
    /*
    @brief create a new node
    @param data integer
    @return node pointer

    @details
    creates a new node with the given data

    @note
    time: O(1)
    space: O(1)
    */
    node *new_node = (node *)malloc(sizeof(node));
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}

node *insert_node(node *head, int data) {
    /*
    @brief insert a new node
    @param head node pointer
    @param data integer
    @return node pointer

    @details
    inserts a new node with the given data at the head of the list

    @note
    time: O(1)
    space: O(1)
    */
    node *new_node = create_node(data);
    new_node->next = head;
    return new_node;
}

node *append_node(node *head, int data) {
    /*
    @brief append a new node
    @param head node pointer
    @param data integer
    @return node pointer

    @details
    appends a new node with the given data at the end of the list

    @note
    time: O(n)
    space: O(1)
    */
    node *new_node = create_node(data);
    if (head == NULL) {
        return new_node;
    }
    node *curr = head;
    while (curr->next != NULL) {
        curr = curr->next;
    }
    curr->next = new_node;
    return head;
}

node *delete_node(node *head, int data) {
    /*
    @brief delete a node
    @param head node pointer
    @param data integer
    @return node pointer

    @details
    deletes the first node with the given data

    @note
    time: O(n)
    space: O(1)
    */
    node *curr = head;
    node *prev = NULL;
    while (curr != NULL) {
        if (curr->data == data) {
            if (prev == NULL) {
                head = curr->next;
            } else {
                prev->next = curr->next;
            }
            free(curr);
            return head;
        }
        prev = curr;
        curr = curr->next;
    }
}

void print_list(node *head) {
    /*
    @brief output the list
    @param head node pointer

    @details
    prints the list

    @note
    time: O(n)
    space: O(1)
    */
    node *curr = head;
    while (curr != NULL) {
        printf("%d ", curr->data);
        curr = curr->next;
    }
}

void free_list(node *head) {
    /*
    @brief clear memory
    @param head node pointer

    @details
    frees the list

    @note
    time: O(n)
    space: O(1)
    */
    node *curr = head;
    node *next;
    while (curr != NULL) {
        next = curr->next;
        free(curr);
        curr = next;
    }
}

#endif