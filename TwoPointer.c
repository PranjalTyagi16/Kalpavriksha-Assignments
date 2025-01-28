#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct Node {
    int data;
    struct Node* next;
};

int detectLoop(struct Node* head) {
    struct Node *slow=head,*fast=head;
    while(slow&&fast&&fast->next) {
        slow=slow->next;
        fast=fast->next->next;
        if (slow==fast)
            return true;
    }
    return false;
}

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}
int main() {

  
    struct Node* head=createNode(1);
    head->next=createNode(3);
    head->next->next=createNode(4);
  
    // Create a loop
    head->next->next->next=head->next;

    if (detectLoop(head))
        printf("true");
    else
        printf("false");

    return 0;
}