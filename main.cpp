// Ruben Navarro
// 02/13/2020
// Given a non-empty, singly linked list with head node head, returns a middle node of linked list.
// main.cpp

#include <iostream>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

// display list
void displayList(ListNode* head) {

    if (head == NULL) {
        std::cout << "head is NULL\n";
        return;
    }
    std::cout << "[";
    while (head != NULL) {
        std::cout << head->val;
        if (head->next != NULL)
            std::cout << ", ";
        head = head->next;
    }
    std::cout << "]" << std::endl;
}

int main() {

    // contructs list
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);
    head->next->next->next->next->next = NULL;

    // returns 0 if head is null
    if (head == NULL) {
        displayList(head);
        return 0;
    }
    // if only a single node is present, displays node
    else if(head != NULL && head->next == NULL) {
        displayList(head);
        return 0;
    }

    // if only 2 nodes in list moves list forward and displays list
    if (head->next->next == NULL) {
        head = head->next;
        displayList(head);
        return 0;
    }

    // pointers to traverse list
    ListNode * curr = head;
    ListNode * prev = head;

    // counter for amount of nodes in list
    int counter1 = 0;

    // counts nodes in list
    while (curr != NULL) {
        curr = curr->next;
        ++counter1;
    }

    curr = head;
    int n = counter1 / 2;

    // moves pointers to construct middle of linked list
    while (curr != NULL && n != 0) {
        curr = curr->next;
        head->val = curr->val;
        head->next = curr->next;

        --n;
    }
    // displays list
    displayList(head);
    return 0;
}
