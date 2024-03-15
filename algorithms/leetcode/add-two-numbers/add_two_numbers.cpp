#include <iostream>

//list node
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

//linked list
class LinkedList {
    public:
        ListNode *head;
        ListNode *tail;
        LinkedList() : head(nullptr), tail(nullptr) {}
        void append(int val) {
            ListNode *new_node = new ListNode(val);
            if (head == nullptr) {
                head = new_node;
                tail = new_node;
            } else {
                tail->next = new_node;
                tail = new_node;
            }
        }
        void display() {
            ListNode *current = head;
            while (current != nullptr) {
                std::cout << current->val << " ";
                current = current->next;
            }
            std::cout << std::endl;
        }
};

class Solution {
    public:
        ListNode* addTwoNumbers(ListNode*, ListNode*);
}

ListNode * Solution::addTwoNumbers(ListNode *l1, ListNode *l2) {
    
}