/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2){
    struct ListNode *temp1=list1;
    
    if(list1==NULL && list2==NULL)
        return NULL;
    if(list1==NULL)
        return list2;
    if(list2==NULL)
        return list1;
    
    while(temp1!=NULL){
        if(temp1->val<=list2->val)
            temp1=temp1->next; 
        else{
            int c=temp1->val;
            temp1->val=list2->val;
            list2->val=c;
            
            struct ListNode *temp2=list2,*temp3=list2->next;
            for(;temp2!=NULL && temp3!=NULL && temp2->val>temp3->val;){
                c=temp2->val;
                temp2->val=temp3->val;
                temp3->val=c;
                
                temp2=temp2->next;
                temp3=temp3->next;
            }
            temp1=temp1->next;
        }
    }
    
    struct ListNode *head=list1,*temp=list1;
    while(temp->next!=NULL)
        temp=temp->next;
    temp->next=list2;
    
    return head;
}