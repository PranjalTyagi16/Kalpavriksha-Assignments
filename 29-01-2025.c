#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
typedef struct Node{
    int value;
    struct Node *next;
}ListNode;

void createAndInsert(ListNode **head,int value)
{
    ListNode *node=(ListNode *)malloc(sizeof(ListNode));
    node->value=value;
    node->next=NULL;
    if(*head==NULL)
    {
      *head=node;
      return;
    }
    ListNode *temp=*head;
    while(temp->next!=NULL)
    {
        temp=temp->next;
    }
    temp->next=node;
    return;
}

int middle(ListNode *head)
{
    ListNode *fast=head;
    ListNode *slow=head;
    while(fast!=NULL&&fast->next!=NULL)
    {
        fast=fast->next->next;
        slow=slow->next;
    }
    return slow->value;
}

ListNode *reverse(ListNode *head)
{
    if(head==NULL||head->next==NULL)
    {
        return head;
    }
    ListNode *newhead=reverse(head->next);
    head->next->next=head;
    head->next=NULL;
    return newhead;

}

int cycle(ListNode *head)
{
    ListNode *fast=head;
    ListNode *slow=head;
    while(fast!=NULL&&fast->next!=NULL)
    {
        fast=fast->next->next;
        slow=slow->next;
        if(slow==fast)
        {
            return 1;
        }
    }
    return 0;
}

int main()
{
  char *input=(char *)malloc(10000*sizeof(char));
  scanf("%[^\n]%*c",input);
  char *ptr=input;
  int *temp=(int *)malloc(1000*sizeof(int));
  int index=0;
  while(*ptr!='\0')
  {
    if(isdigit(*ptr))
    {
        int num;
        sscanf(ptr,"%d",&num);
        temp[index++]=num;
        while(isdigit(*ptr))
        {
            ptr++;
        }
    }
    else{
        ptr++;
    }
  }
  ListNode *head=NULL;
  for(int i=0;i<index;i++)
  {
    createAndInsert(&head,temp[i]);
  }
  int ans=middle(head);
  ListNode *newhead=reverse(head);
  ListNode *trav=newhead;
  while(trav!=NULL)
  {
    printf("%d ",trav->value);
    trav=trav->next;
  }
  printf("\n");
  printf("%d\n",ans);
  return 0;
}