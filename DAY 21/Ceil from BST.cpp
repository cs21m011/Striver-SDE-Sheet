/************************************************************

    Following is the TreeNode class structure:

    class BinaryTreeNode {
    public:
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;
        
        BinaryTreeNode(T data) {
            this->data = data;
            left = NULL;
            right = NULL;
        }
        
        ~BinaryTreeNode() {
            if (left) {
              delete left;
            }
            if (right) {
              delete right;
            }
        }
    };

************************************************************/

void inOrder(BinaryTreeNode<int>*,int,int&);

int findCeil(BinaryTreeNode<int> *node, int x){
    // Write your code here.
    int res=-1;
    inOrder(node,x,res);
    return res;
}

void inOrder(BinaryTreeNode<int>* root,int x,int& res){
    if(root==NULL)
        return;
    
    //if element is found then it is the floor
    if(root->data==x)
        res=root->data;
    else if(root->data>x)
        inOrder(root->left,x,res);
    else if(root->data<x)
        inOrder(root->right,x,res);
    
    //the element which is greater than x and occurs first time
    if(root->data>x && res==-1)
        res=root->data;
}