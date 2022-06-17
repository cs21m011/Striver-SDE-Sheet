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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        map<int,int> m;
        for(int i=0;i<inorder.size();i++)
            m[inorder[i]]=i;
        
        return constructTree(preorder,inorder,0,preorder.size()-1,0,inorder.size()-1,m);
    }
    
    TreeNode* constructTree(vector<int>& preorder,vector<int>& inorder,int preStart,int preEnd,int inStart,int inEnd,map<int,int>& m){
        if((preStart>preEnd) || (inStart>inEnd))
            return NULL;
        
        TreeNode* root=new TreeNode(preorder[preStart]);
        
        int index=m[root->val];
        int elements_left=index-inStart;
        
        //getting the nodes that happen on left side of root
        root->left=constructTree(preorder,inorder,preStart+1,preStart+elements_left,inStart,index-1,m);
        
        //getting the nodes that happen on right side of root
        root->right=constructTree(preorder,inorder,preStart+elements_left+1,preEnd,index+1,inEnd,m);
        
        return root;
    }
};