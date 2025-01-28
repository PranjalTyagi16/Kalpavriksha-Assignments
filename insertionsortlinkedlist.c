#include <stdio.h>
#include <stdlib.h>
struct Node {
    int val;
    struct Node* next;
};
struct Node* sortedInsert(struct Node* createNode,struct Node* sorted) {
    if (sorted==NULL||sorted->val >= createNode->val){
        createNode->next = sorted;
        sorted = createNode;
    }
    else{
        struct Node* curr=sorted;
        while (curr->next!=NULL&&curr->next->val < createNode->val) {
            curr = curr->next;
        }
        createNode->next=curr->next;
        curr->next=createNode;
    }    
    return sorted;
}
struct Node* insertionSort(struct Node* head){
    struct Node* sorted=NULL;
    struct Node* curr=head;
    while (curr!=NULL){
        struct Node* next=curr->next;
        sorted=sortedInsert(curr, sorted);
        curr=next;
    }    
    return sorted;
}
void printList(struct Node* curr){
    while (curr!=NULL) {
        printf(" %d",curr->val);
        curr=curr->next;
    }
    printf("\n");
}
struct Node* createNode(int x){
    struct Node* node=(struct Node*)malloc(sizeof(struct Node));
    node->val=x;
    node->next=NULL;
    return node;
}
int main(){
    int n,val;
    struct Node* head=NULL;
    struct Node* tail=NULL;
    printf("Enter the number of elements in the linked list: ");
    scanf("%d",&n);
    printf("Enter %d elements: ",n);
    for (int i=0; i<n; ++i){
        scanf("%d", &val);
        struct Node* newNode = createNode(val);
        if (head == NULL) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }
    printf("Original linked list: ");
    printList(head);
    head = insertionSort(head);
    printf("Sorted linked list: ");
    printList(head);
    return 0;
}
