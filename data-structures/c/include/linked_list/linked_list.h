/*
@gitsil10
S Flores

@date
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
delete -> deletes the first node with the given data
print -> prints the list
free -> frees the list | clear memory
*/
#include <stdio.h>
#include <stdlib.h>

#ifndef LINKED_LIST_H
#define LINKED_LIST_H

//data
typedef struct node {
    int data;
    struct node *next;
} node;

//prototypes
node *create_node(int data);
node *insert_node(node *head, int data);
node *delete_node(node *head, int data);
void print_list(node *head);
void free_list(node *head);


#endif