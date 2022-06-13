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
    int widthOfBinaryTree(TreeNode* root) {
        queue<pair<TreeNode*,int>> q;
        q.push({root,0});
        int res=0;
        
        while(!q.empty()){
            int k=q.size(),left=0,right=0,cur_min=q.front().second;
            
            for(int i=0;i<k;i++){
                auto it=q.front();
                int l=it.second-cur_min;
                q.pop();
                
                //finding the values of left most node and right most node in the level
                if(i==0)
                    left=l;
                if(i==k-1)
                    right=l;
                
                TreeNode *p=it.first;
                if(p->left!=NULL)
                    q.push({p->left,l*2+1});
                if(p->right!=NULL)
                    q.push({p->right,l*2+2});
            }
            if((right-left+1)>res)
                res=right-left+1;
        }
        return res;
    }
};