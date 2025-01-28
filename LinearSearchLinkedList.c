#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
struct Node{
    int data;
    struct Node* next;
};
struct Node* createNode(int new_data){
    struct Node* new_node=(struct Node*)malloc(sizeof(struct Node));
    new_node->data=new_data;
    new_node->next=NULL;
    return new_node;
}
bool searchKey(struct Node* head, int key){
    struct Node* curr=head;
    while(curr!=NULL){
        if (curr->data==key)
            return true;
        curr=curr->next;
    }
    return false;
}
int main(){
    int n,value,key;
    struct Node* head=NULL;
    struct Node* tail=NULL;
    printf("Enter the number of elements in the linked list: ");
    scanf("%d",&n);
    printf("Enter %d elements: ",n);
    for (int i=0;i<n;i++) {
        scanf("%d",&value);
        struct Node* newNode=createNode(value);
        if(head==NULL){
            head=newNode;
            tail=newNode;
        }else{
            tail->next=newNode;
            tail=newNode;
        }
    }
    printf("Enter the value to search: ");
    scanf("%d", &key);
    if (searchKey(head, key))
        printf("Value is Present\n");
    else
        printf("Value is Not Present\n");
    return 0;
}
