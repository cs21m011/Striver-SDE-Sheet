/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 
 void findPath(TreeNode*,vector<int>&,int);
 
vector<int> Solution::solve(TreeNode* A, int B) {
    if(A==NULL)
        return {};
        
    vector<int> v;
    findPath(A,v,B);
    return v;
}

void findPath(TreeNode* A,vector<int>& v,int B){
    if(A==NULL)
        return;
        
    if(A->val==B){
        v.push_back(B);
        return;
    }    

    v.push_back(A->val);
    if(A->left!=NULL && v[v.size()-1]!=B)
        findPath(A->left,v,B);
    if(A->right!=NULL && v[v.size()-1]!=B)
        findPath(A->right,v,B);
    
    if(v[v.size()-1]!=B)
        v.pop_back();
}
