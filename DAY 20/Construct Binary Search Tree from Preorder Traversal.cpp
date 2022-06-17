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
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int index=0;
        return constructBST(preorder,index,INT_MIN,INT_MAX);
    }
    
    TreeNode* constructBST(vector<int>& preorder,int& index,int min,int max){
        if(index<preorder.size() && preorder[index]>min && preorder[index]<max){
            TreeNode* root=new TreeNode(preorder[index++]);
            
            root->left=constructBST(preorder,index,min,preorder[index]);
            root->right=constructBST(preorder,index,preorder[index],max);
            
            return root;
        }
        return NULL;
    }
};