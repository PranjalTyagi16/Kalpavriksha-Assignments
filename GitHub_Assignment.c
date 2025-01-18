#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

Node* head = NULL;

Node* createNode(int value) {
    Node* newNode=(Node*)malloc(sizeof(Node));
    newNode->data=value;
    newNode->next=NULL;
    return newNode;
}


void insertAtBeginning(int value) {
    Node* newNode=createNode(value);
    newNode->next=head;
    head=newNode;
}


void insertAtEnd(int value) {
    Node* newNode=createNode(value);
    if (head==NULL) {
        head=newNode;
        return;
    }
    Node *temp=head;
    while(temp->next!=NULL) 
    {
        temp=temp->next;
    }
    temp->next=newNode;
}


void insertAtPosition(int position, int value) {
    if (position<1) {
        printf("Invalid position\n");
        return;
    }
    if (position==1) {
        insertAtBeginning(value);
        return;
    }
    Node* newNode=createNode(value);
    Node* temp=head;
    for (int i=1; i<position-1&&temp!=NULL;i++) {
        temp=temp->next;
    }
    if (temp==NULL) {
        printf("Invalid position\n");
        return;
    }
    newNode->next=temp->next;
    temp->next=newNode;
}


void display() 
{
    if(head==NULL) {
        printf("List is empty\n");
        return;
    }
    Node* temp=head;
    while (temp!=NULL) 
    {
        printf("%d ", temp->data);
        temp=temp->next;
    }
    printf("\n");
}


void updateAtPosition(int position,int newValue) {
    if (position<1) {
        printf("Invalid position\n");
        return;
    }
    Node* temp=head;
    for (int i =1;i<position&&temp!=NULL;i++) {
        temp = temp->next;
    }
    if (temp==NULL) {
        printf("Invalid position\n");
        return;
    }
    temp->data = newValue;
}


void deleteAtBeginning() {
    if (head==NULL) {
        printf("List is empty\n");
        return;
    }
    Node* temp=head;
    head=head->next;
}


void deleteAtEnd() {
    if (head==NULL) {
        printf("List is empty\n");
        return;
    }
    if (head->next==NULL) {
        head = NULL;
        return;
    }
    Node* temp=head;
    while (temp->next->next !=NULL) {
        temp=temp->next;
    }
    temp->next=NULL;
}


void deleteAtPosition(int position) {
    if (position<1) {
        printf("Invalid position\n");
        return;
    }
    if (position==1) {
        deleteAtBeginning();
        return;
    }
    Node* temp=head;
    for (int i=1; i<position-1&&temp!=NULL;i++) {
        temp=temp->next;
    }
    if (temp==NULL||temp->next==NULL) {
        printf("Invalid position\n");
        return;
    }
    Node* toDelete=temp->next;
    temp->next=toDelete->next;
    free(toDelete);
}

int main() {
    int n, op, val, pos;
    scanf("%d", &n);
    for (int i=0; i<n;i++) {
        scanf("%d",&op);
        switch (op) {
            case 1: 
                scanf("%d",&val);
                insertAtEnd(val);
                break;
            case 2: 
                scanf("%d", &val);
                insertAtBeginning(val);
                break;
            case 3: 
                scanf("%d %d", &pos, &val);
                insertAtPosition(pos,val);
                break;
            case 4: 
                display();
                break;
            case 5:
                scanf("%d %d",&pos,&val);
                updateAtPosition(pos,val);
                break;
            case 6:
                deleteAtBeginning();
                break;
            case 7:
                deleteAtEnd();
                break;
            case 8:
                scanf("%d",&pos);
                deleteAtPosition(pos);
                break;
            default:
                printf("Invalid operation\n");
        }
    }
    return 0;
}