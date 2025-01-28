#include <stdio.h>
#include <stdlib.h>
struct Node {
    int data;
    struct Node* next;
};

void selectionSortLinkedList(struct Node* head) {
    struct Node *temp1 = head, *temp2, *min;
    while (temp1) {
        min = temp1;
        temp2 = temp1->next;
        while (temp2) {
            if (temp2->data < min->data) min = temp2;
            temp2 = temp2->next;
        }
        int temp = temp1->data;
        temp1->data = min->data;
        min->data = temp;
        temp1 = temp1->next;
    }
}
/* Time Complexity: O(n^2) | Space Complexity: O(1) */
