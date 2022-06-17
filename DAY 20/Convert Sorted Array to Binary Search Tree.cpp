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
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return constructBST(nums,0,nums.size()-1);
    }
    
    TreeNode* constructBST(vector<int>& nums,int low,int high){
        if(low<=high){
            int mid=(low+high)/2;
            
            TreeNode* node=new TreeNode(nums[mid]);
            node->left=constructBST(nums,low,mid-1);
            node->right=constructBST(nums,mid+1,high);
            
            return node;
        }
        return NULL;
    }
};