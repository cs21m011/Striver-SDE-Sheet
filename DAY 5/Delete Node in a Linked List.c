/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
void deleteNode(struct ListNode* node) {
    struct ListNode *temp=node;
    while(temp->next!=NULL){
        temp->val=temp->next->val;
        if(temp->next->next==NULL)
            temp->next=NULL;
        else
            temp=temp->next;
    }
}