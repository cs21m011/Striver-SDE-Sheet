/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* middleNode(struct ListNode* head){
    int n=0,middle=0;
    
    //finding the length of linked list
    struct ListNode *temp=head;
    while(temp!=NULL){
        n++;
        temp=temp->next;    
    }
    
    middle=n/2;
    struct ListNode *temp1=head;
    //incrementing the pointer until middle node
    for(int i=0;i<middle;i++)
        temp1=temp1->next;
    
    return temp1;
}