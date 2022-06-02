/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


bool isPalindrome(struct ListNode* head){
    //reversing the list
    struct ListNode *before=NULL,*temp=head,*after=head->next;
    while(temp!=NULL){
        after=temp->next;
        temp->next=before;

        before=temp;
        temp=after;
    }
    head=before;

    //creating a new linked list and copying the reversed list elements
    struct ListNode *temp1=before,*head_new=NULL,*p=NULL;
    if(temp1!=NULL){
        p=(struct ListNode *)malloc(sizeof(struct ListNode));
        p->val=temp1->val;
        p->next=NULL;
        
        head_new=p;
        temp1=temp1->next;
    }
    
    while(temp1!=NULL){
        struct ListNode *q=(struct ListNode *)malloc(sizeof(struct ListNode));
        q->val=temp1->val;
        q->next=NULL;
        p->next=q;
        p=p->next;
        
        temp1=temp1->next;
    }
    
    //again reversing the original list
    struct ListNode *before1=NULL,*temp2=head,*after1=head->next;
    while(temp2!=NULL){
        after1=temp2->next;
        temp2->next=before1;

        before1=temp2;
        temp2=after1;
    }
    head=before1;
        
    //comparing the numbers in both lists
    struct ListNode *cmp1=head,*cmp2=head_new;
    while(cmp1!=NULL && cmp2!=NULL){
        if(cmp1->val!=cmp2->val)
            return false;
        cmp1=cmp1->next;
        cmp2=cmp2->next;
    }
    return true;
}