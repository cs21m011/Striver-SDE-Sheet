/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        struct ListNode *temp=head;
        
        unordered_set<ListNode*> hmap;
        while(temp!=NULL){
            if(hmap.find(temp)!=hmap.end())
                return temp;
            hmap.insert(temp);
            temp=temp->next;
        }
        return NULL;
    }
};