/************************************************************

    Following is the Binary Tree node structure:

    class BinaryTreeNode
    {
    public :
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }
    };


************************************************************/

void preOrder(BinaryTreeNode<int>*,vector<int>&);
void inOrder(BinaryTreeNode<int>*,vector<int>&);
void postOrder(BinaryTreeNode<int>*,vector<int>&);

vector<vector<int>> getTreeTraversal(BinaryTreeNode<int> *root){
    //inorder traversal
    vector<int> in;
    inOrder(root,in);
    //preorder traversal
    vector<int> pre;
    preOrder(root,pre);
    
    //postorder traversal
    vector<int> post;
    postOrder(root,post);
    
    vector<vector<int>> v;
    v.push_back(in);
    v.push_back(pre);
    v.push_back(post);
    return v;
}

void inOrder(BinaryTreeNode<int>* root,vector<int>& in){
    if(root==NULL)
        return;
    
    inOrder(root->left,in);
    in.push_back(root->data);
    inOrder(root->right,in);
}

void preOrder(BinaryTreeNode<int>* root,vector<int>& pre){
    if(root==NULL)
        return;
    
    pre.push_back(root->data);
    preOrder(root->left,pre);
    preOrder(root->right,pre);
}

void postOrder(BinaryTreeNode<int>* root,vector<int>& post){
    if(root==NULL)
        return;
    
    postOrder(root->left,post);
    postOrder(root->right,post);
    post.push_back(root->data);
}