/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        int res=-1,counter=0;
        inOrder(root,k,res,counter);
        return res;
    }
    
    void inOrder(TreeNode* root,int k,int& res,int& counter){
        if(root==NULL)
            return;
        
        inOrder(root->left,k,res,counter);
        
        //no need to iterate if counter exceeds k
        if(counter>k)
            return;
        
        //incrementing counter for every value reached. counter will be incremented from last level 
        counter++;
        if(counter==k){
            res=root->val;
            return;
        }
        
        inOrder(root->right,k,res,counter);
    }
};