/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* removeNthFromEnd(struct ListNode* head, int n){
    struct ListNode *temp=head;
    long len=0;
    while(temp!=NULL){
        len++;
        temp=temp->next;    
    }
    
    if(len==1 && n==1){
        free(head);
        return NULL;
    }
    if(n==len){
        head=head->next;
        return head;
    }
    
    long number_from_left=len-n+1;
    struct ListNode *temp1=head;
    for(long i=1;i<number_from_left-1;i++,temp1=temp1->next);
    
    struct ListNode *temp2=temp1->next;
    if(temp2!=NULL)
        temp1->next=temp2->next;
    free(temp2);
    
    return head;
}