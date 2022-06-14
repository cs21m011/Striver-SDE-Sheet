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
    bool isBalanced(TreeNode* root) {
        int diff=findHeight(root);
        
        if(diff!=-1)
            return true;
        return false;
    }
    
    int findHeight(TreeNode* root){
        if(root==NULL) 
            return 0;
        
        int leftHeight=findHeight(root->left);
        int rightHeight=findHeight(root->right);
        
        //if tree is imbalanced, return -1
        if(leftHeight==-1 || rightHeight==-1 || abs(leftHeight-rightHeight)>1)  
            return -1;

        //otherwise return actual height
        return leftHeight>rightHeight?leftHeight+1:rightHeight+1;
    }
};