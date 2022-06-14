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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if(root==NULL)
            return res;
        
        queue<TreeNode*> q;
        q.push(root);
        
        int level=0;
        while(!q.empty()){
            int k=q.size();
            
            vector<int> v;
            for(int i=0;i<k;i++){
                TreeNode* p=q.front();
                q.pop();
                v.push_back(p->val);
                
                if(p->left!=NULL)
                    q.push(p->left);
                if(p->right!=NULL)
                    q.push(p->right);
            }
            
            //pushing into resulting vector based on the level
            if(level%2==0)
                res.push_back(v);
            else{
                vector<int> rev_v;
                for(int i=v.size()-1;i>=0;i--)
                    rev_v.push_back(v[i]);
                res.push_back(rev_v);
            }
            level++;
        }
        return res;
    }
};