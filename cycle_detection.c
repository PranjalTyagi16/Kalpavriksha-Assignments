// Complete the has_cycle function below.

/*
 * For your reference:
 *
 * SinglyLinkedListNode {
 *     int data;
 *     SinglyLinkedListNode* next;
 * };
 *
 */
bool has_cycle(SinglyLinkedListNode* head) {
 if(head==NULL)
 {
     return false;
 }
    SinglyLinkedListNode* fast=head;
    SinglyLinkedListNode* slow=head;
    while(fast!=NULL&&fast->next!=NULL)
    {
        fast=fast->next->next;
        slow=slow->next;
         if(fast==slow)
         {
           return true;
         }
    }
    return false;

}