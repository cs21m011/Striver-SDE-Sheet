class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> v;
        vector<int> k;
        
        sort(nums.begin(),nums.end());
        int n=nums.size();
        fun(nums,n,0,v,k);
        return v;
    }
    
    void fun(vector<int>& nums,int n,int index,vector<vector<int>>& v,vector<int>& k){
        v.push_back(k);
        
        for(int i=index;i<n;i++){
            if(i==index || nums[i]!=nums[i-1]){
                 k.push_back(nums[i]);
                 fun(nums,n,i+1,v,k); 
                 k.pop_back();
            }
        }
    }
};