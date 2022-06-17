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
    bool isValidBST(TreeNode* root) {
        if(root==NULL)
            return true;
        if(root->left==NULL && root->right==NULL)
            return true;
        
        
        return checkBST(root,INT_MIN,INT_MAX);
    }
    
    bool checkBST(TreeNode* root,long min,long max){
        if(root==NULL)
            return true;
        
        if(root->val>min && root->val<max)
            return checkBST(root->left,min,root->val) && checkBST(root->right,root->val,max);
        
        if(root->val==INT_MIN || root->val==INT_MAX)
            return checkBST(root->left,min,root->val) && checkBST(root->right,root->val,max);
        
        return false;
    }
};