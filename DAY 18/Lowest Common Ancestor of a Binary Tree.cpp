/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution{
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root==NULL)
            return NULL;
        if(root==p || root==q)
            return root;
       
        
        TreeNode *path_to_p=lowestCommonAncestor(root->left,p,q);
        TreeNode *path_to_q=lowestCommonAncestor(root->right,p,q);
        
        if(path_to_p!=NULL && path_to_q!=NULL)
            return root;
        return path_to_p==NULL?path_to_q:path_to_p;
    }
};