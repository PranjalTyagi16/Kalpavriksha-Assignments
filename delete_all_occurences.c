#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <ctype.h>
typedef struct Node
{
    int data;
    struct Node *next;
}ListNode;

ListNode *createNode(int value)
{
    ListNode *newnode=(ListNode *)malloc(sizeof(ListNode));
    newnode->data=value;
    newnode->next=NULL;
    return newnode;
}

void insertAtEnd(ListNode **head,ListNode *newnode)
{
    if(*head==NULL)
    {
        *head=newnode;
        return;
    }
    ListNode *temp=*head;
    while(temp->next!=NULL)
    {
        temp=temp->next;
    }
    temp->next=newnode;
    return;
}

ListNode *deleteNode(ListNode **head,ListNode *node)
{
    if(*head==NULL)
    {
        return NULL;
    }
    if(node==*head)
    {
        return NULL;
    }
    ListNode *cur=*head;
    ListNode *prev=NULL;
    while(cur!=node)
    {
        prev=cur;
        cur=cur->next;
    }
    prev->next=cur->next;
    free(node);
    return *head;
    
}

int main() {

    /* Enter your code here. Read input from STDIN. Print output to STDOUT */ 
    char *input=(char *)malloc(1000*sizeof(char));
    scanf("%[^\n]%*c",input);
    int k;
    scanf("%d",&k);
    getchar();
    int *temp=(int *)malloc(10000*sizeof(int));
    int index=0;
    char *ptr=input;
    while(*ptr!='\0')
    {
        if(isdigit(*ptr)||*ptr=='-')
        {
            int num;
            sscanf(ptr,"%d",&num);
            temp[index++]=num;
            while(isdigit(*ptr)||*ptr=='-')
            {
                ptr++;
            }
        }
        else
        {
            ptr++;
        }
    }
    ListNode *head=NULL;
    if(index==0)
    {
        printf(" ");
    }
    int size=index;
    index=0;
    while(index!=size){
    ListNode *newnode=createNode(temp[index++]);
        insertAtEnd(&head,newnode);
    }
    ListNode *newhead=head;
    while(newhead!=NULL)
    {
        if(newhead->data==k)
        {
            ListNode *tempo=newhead;
            newhead=newhead->next;
            head=deleteNode(&head,tempo);
        }
        else
        {
            newhead=newhead->next;
        }
    }
    ListNode *t=head;
    while(t!=NULL)
    {
        printf("%d ",t->data);
        t=t->next;
    }
    printf("\n");
    return 0;
}
