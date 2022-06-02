/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* rotateRight(struct ListNode* head, int k){
    if(head==NULL)
        return NULL;
    if(head->next==NULL)
        return head;
    
    //finding the length of list
    struct ListNode *p=head;
    long len=0;
    while(p!=NULL){
        len++;
        p=p->next;
    }
    
    //iterating only for k%len times because the list will not change after no.of iterations==length 
    for(int i=1;i<=(k%len);i++){
        struct ListNode *temp=head;
        while(temp->next->next!=NULL)
            temp=temp->next;

        temp->next->next=head;
        head=temp->next;
        temp->next=NULL;
    }
    return head;
}