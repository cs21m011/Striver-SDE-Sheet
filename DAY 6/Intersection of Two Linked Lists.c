/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode *getIntersectionNode(struct ListNode *headA, struct ListNode *headB) {
    struct ListNode *temp1=headA,*temp2=headB;
    
    //finding the length both lists
    long m=0,n=0;
    while(temp1!=NULL){
        m++;
        temp1=temp1->next;
    }
    while(temp2!=NULL){
        n++;
        temp2=temp2->next;
    }
    
    //moving the larger list pointer ahead to decrease the no. of iterations
    long len_diff=m>n?m-n:n-m;
    struct ListNode *temp3=headA,*temp4=headB;
    if(m>n){
       for(long i=0;i<len_diff;i++)
           temp3=temp3->next;
    }
    else{
        for(long i=0;i<len_diff;i++)
           temp4=temp4->next;
    }
    
    //finding the intersection point
    while(temp4!=NULL){
        struct ListNode *temp=temp3;
        while(temp!=NULL){
            if(temp!=temp4)
                temp=temp->next;
            else
                return temp;
        }
        temp4=temp4->next;
        temp3=temp3->next;
    }
    return NULL;
}