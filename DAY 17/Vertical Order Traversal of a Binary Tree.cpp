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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int,map<int,multiset<int>>> nodes;
        queue<pair<TreeNode*,pair<int,int>>> q;
        q.push({root,{0,0}});
        
        while(!q.empty()){
            auto it=q.front();
            q.pop();
            
            //pushing the first node in vertical into map
            TreeNode* p=it.first;
            int vertical=it.second.first,level=it.second.second;
            nodes[vertical][level].insert(p->val);
            
            if(p->left!=NULL)
                q.push({p->left,{vertical-1,level+1}});
            if(p->right!=NULL)
                q.push({p->right,{vertical+1,level+1}});    
            
        }
        
        vector<vector<int>> v;
        for(auto p:nodes){
            vector<int> k;
            for(auto q:p.second)
                k.insert(k.end(),q.second.begin(),q.second.end());
            v.push_back(k);
        }
        return v;
    }
};