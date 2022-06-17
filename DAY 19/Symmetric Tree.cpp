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
    bool isSymmetric(TreeNode* root) {
        if(root==NULL)
            return true;
        if(root->left==NULL && root->right==NULL)
            return true;
        
        bool res=find(root->left,root->right);
        return res;
    }
    
    bool find(TreeNode* root_left,TreeNode* root_right){
        if(root_left==NULL && root_right!=NULL)
            return false;
        if(root_right==NULL && root_left!=NULL)
            return false;
        if(root_left==NULL && root_right==NULL)
            return true;
            
        if(root_left->val!=root_right->val)
            return false;
        
        return find(root_left->left,root_right->right) && find(root_left->right,root_right->left);
    }
};