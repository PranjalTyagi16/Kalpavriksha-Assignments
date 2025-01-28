#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};
int getLength(struct Node *head) {
    int len = 0;
    struct Node *curr = head;
    while (curr != NULL) {
        len++;
        curr = curr->next;
    }
    return len;
}

struct Node *bubbleSort(struct Node *head) {
    struct Node *currNode = head;
    int len = getLength(head);
    int itr = 0;
    int swapped;

    while (itr < len) {
        struct Node *traverseNode = head;
        struct Node *prevNode = head;
        swapped = 0;

        while (traverseNode->next != NULL) {
            struct Node *ptr = traverseNode->next;
            if (traverseNode->data > ptr->data) {
                swapped = 1;
                if (traverseNode == head) {
                    traverseNode->next = ptr->next;
                    ptr->next = traverseNode;
                    prevNode = ptr;
                    head = prevNode;
                } else {
                    traverseNode->next = ptr->next;
                    ptr->next = traverseNode;
                    prevNode->next = ptr;
                    prevNode = ptr;
                }
                continue;
            }
            prevNode = traverseNode;
            traverseNode = traverseNode->next;
        }

        if (!swapped) {
            break;
        }
        ++itr;
    }
    return head;
}

void printList(struct Node *curr) {
    while (curr != NULL) {
        printf("%d -> ",curr->data);
        curr=curr->next;
    }
    printf("NULL\n");
}

struct Node *createNode(int x) {
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = x;
    newNode->next = NULL;
    return newNode;
}
void insertNode(struct Node **head, int data) {
    struct Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    struct Node* temp = *head;
    while (temp->next) temp = temp->next;
    temp->next = newNode;
}

int main() {
    struct Node *head=NULL;
    int n,value;
    
    printf("Enter the number of elements in the linked list: ");
    scanf("%d",&n);
    
    printf("Enter the elements:\n");
    for (int i=0; i<n;i++) {
        scanf("%d",&value);
        insertNode(&head,value);
    }
    
    printf("Original Linked List:\n");
    printList(head);
    
    head = bubbleSort(head);
    
    printf("Sorted Linked List:\n");
    printList(head);
    
    return 0;
}