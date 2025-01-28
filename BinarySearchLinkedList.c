#include <stdio.h>
#include <stdlib.h>
struct Node {
    int data;
    struct Node* next;
};
struct Node* createNode(int new_data){
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = new_data;
    new_node->next = NULL;
    return new_node;
}
struct Node* middle(struct Node* start, struct Node* end) {
    struct Node* slow=start;
    struct Node* fast=start;
    while(fast!=end&&fast->next!=end){
        slow=slow->next;
        fast=fast->next->next;
    }
    return slow;
}
int binarySearch(struct Node* head,int value){
    struct Node* start=head;
    struct Node* end=NULL;
    while (start!=end){
        struct Node* mid=middle(start,end);
        if (mid==NULL)
        {
            return 0; 
        }
        if (mid->data==value)
        {
            return 1; 
        } else if(mid->data<value)
        {
            start=mid->next; 
        }else
        {
            end=mid; 
        }
    }
    return 0; 
}
void printList(struct Node* head){
    struct Node* curr=head;
    while(curr!=NULL) 
    {
        printf("%d ",curr->data);
        curr=curr->next;
    }
    printf("\n");
}
int main(){
    int n, value, searchValue;
    struct Node* head=NULL;
    struct Node* tail=NULL;
    printf("Enter the number of elements in the linked list: ");
    scanf("%d",&n);
    printf("Enter %d elements in sorted order: ",n);
    for (int i=0;i<n;i++) {
        scanf("%d",&value);
        struct Node* newNode=createNode(value);
        if (head==NULL) {
            head=newNode;
            tail=newNode;
        }else{
            tail->next=newNode;
            tail=newNode;
        }
    }
    printf("Enter the value to search: ");
    scanf("%d",&searchValue);
    if (binarySearch(head,searchValue)){
        printf("Value is present\n");
    }else{
        printf("Value is not present\n");
    }
    return 0;
}
