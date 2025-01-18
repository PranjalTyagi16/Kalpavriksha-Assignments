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
void removeKthNode(ListNode **head, int k) {
    if (*head==NULL||k<=0) return;

    ListNode *curr=*head,*prev=NULL;
    int position=1;

    while (curr!=NULL) {
        if (position%k==0) {
            if (prev!=NULL) {
                prev->next=curr->next;
            } else {
                *head=curr->next;
            }
            curr = curr->next;
        } else {
            prev = curr;
            curr=curr->next;
        }
        position++;
    }
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
    
     
    for(int i=0;i<index;i++)
    {
       ListNode *newnode=createNode(temp[i]);
       insertAtEnd(&head,newnode);
        
    }
    removeKthNode(&head,k);
    ListNode *t=head;
     while(t!=NULL)
    {
        printf("%d ",t->data);
        t=t->next;
    }
    printf("\n");
    return 0;
}
