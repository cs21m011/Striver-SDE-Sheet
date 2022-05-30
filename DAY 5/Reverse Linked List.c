/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* reverseList(struct ListNode* head){
    struct ListNode *temp1=NULL;
    
    while(head!=NULL){
        struct ListNode *temp2=head->next;
        head->next=temp1;
        temp1=head;
        head=temp2;
    }
    return temp1;
}