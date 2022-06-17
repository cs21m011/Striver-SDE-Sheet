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
class BSTIterator {
    stack<TreeNode*> s;
public:
    BSTIterator(TreeNode* root) {
        push_into_stack(root);
    }
    
    int next() {
        TreeNode *it=s.top();
        s.pop();
        
        push_into_stack(it->right);
        
        return it->val;
    }
    
    bool hasNext() {
        if(s.empty())
            return false;
        return true;
    }
    
    void push_into_stack(TreeNode* root){
        if(root==NULL)
            return;
        
        s.push(root);
        push_into_stack(root->left);
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */