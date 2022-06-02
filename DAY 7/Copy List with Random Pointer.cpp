/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(head==NULL)
            return NULL;
            
        Node *temp=head;
        //copying the values into new nodes
        while(temp!=NULL){
            Node *p=new Node(temp->val);
            
            p->next=temp->next;
            temp->next=p;
            temp=p->next;
        }
        
        //copying the random pointers to new nodes
        temp=head;
        Node *temp_new=temp->next,*head_new=temp->next;
        while(temp!=NULL){
            temp_new=temp->next;
            if(temp->random==NULL)
                temp_new->random=NULL;
            else
                temp_new->random=temp->random->next;
            
            temp=temp_new->next;
        }
        
        //removing the original nodes
        temp=head;
        temp_new=temp->next;
        while(temp!=NULL){
            temp->next=temp->next->next;
            
            if(temp_new->next==NULL)
                temp_new=NULL;
            else{
                temp_new->next=temp_new->next->next;
                temp_new=temp_new->next;
            }
            temp=temp->next;
        }
        
        return head_new;
    }
};