/************************************************************

    Following is the TreeNode class structure

    template <typename T>
    class TreeNode {
       public:
        T val;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T val) {
            this->val = val;
            left = NULL;
            right = NULL;
        }
    };

************************************************************/
void inOrder(TreeNode<int> *,int,int&);

int floorInBST(TreeNode<int> * root, int X){
    int res=0;
    inOrder(root,X,res);
    return res;
}

void inOrder(TreeNode<int>* root,int X,int& res){
    if(root==NULL)
        return;
    
    //if element is found then it is the floor
    if(root->val==X)
        res=root->val;
    else if(X<root->val)
        inOrder(root->left,X,res);
    else if(X>root->val)
        inOrder(root->right,X,res);
    
    //updating the result with greatest lesser element
    if(root->val<X && root->val>res)
        res=root->val;
}