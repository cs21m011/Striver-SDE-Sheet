/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

/*unsigned long reverse_number(unsigned long);
unsigned long power(unsigned long,unsigned long);

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2){
    unsigned long num1=0,num2=0;
    
    //finding the number1
    struct ListNode *temp1=l1;
    //for zeros at starting of the number
    long p1=0;
    for(;temp1!=NULL && temp1->val==0;temp1=temp1->next)
        p1++;
    
    temp1=l1;
    while(temp1!=NULL){
        num1=num1*10+(temp1->val);
        temp1=temp1->next;
    }
    
    num1=reverse_number(num1);
    if(p1>0)
        num1=num1*power(10,p1);
    
    
    //finding the number2
    struct ListNode *temp2=l2;
    long p2=0;
    for(;temp2!=NULL && temp2->val==0;temp2=temp2->next)
        p2++;
    
    temp2=l2;
    while(temp2!=NULL){
        num2=num2*10+(temp2->val);
        temp2=temp2->next;
    }
    num2=reverse_number(num2);
    if(p2>0)
        num2=num2*power(10,p2);
    
    printf("%ld  %ld",num1,num2);
    
    //finding sum and forming a liinked list
    unsigned long sum=num1+num2;
    struct ListNode *head=(struct ListNode *)malloc(sizeof(struct ListNode));
    head->val=sum%10;
    head->next=NULL;
    sum=sum/=10;
    
    struct ListNode *temp3=head; 
    while(sum>0){
        struct ListNode *temp=(struct ListNode *)malloc(sizeof(struct ListNode));
        temp->val=sum%10;
        temp->next=NULL;
        sum/=10;
        temp3->next=temp;
        temp3=temp;
    }
    return head;
}

unsigned long power(unsigned long x,unsigned long n){
    unsigned long res=1;
    for(unsigned long p=n;p>0;){
        if(p%2==0){
            x=x*x;
            p/=2;
        }
        else{
           res=res*x;
            p--;
        }
    }
    return res;
}

unsigned long reverse_number(unsigned long num){
    long rev=0,k=num;
    while(k>0){
        rev=rev*10+(k%10);
        k/=10;
    }
    return rev;
}*/


struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2){
    struct ListNode *temp1=l1,*temp2=l2,*head=NULL,*temp=NULL;
    
    int carry=0;
    while((temp1!=NULL || temp2!=NULL) || carry!=0){
        int sum=0;
        //finding the sum
        if(temp1!=NULL){
            sum+=temp1->val;
            temp1=temp1->next;
        }
        if(temp2!=NULL){
            sum+=temp2->val;
            temp2=temp2->next;
        }
        sum+=carry;
        carry=sum/10;
        sum=sum%10;
        
        //creating a node with value of sum
        struct ListNode *p=(struct ListNode *)malloc(sizeof(struct ListNode));
        p->val=sum;
        p->next=NULL;
        if(head==NULL){
            head=p;
            temp=p;
        }
        else{
            temp->next=p;
            temp=p;
        }
    }
    return head;
}