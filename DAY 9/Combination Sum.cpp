class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> v;
        vector<int> k;
        
        int n=candidates.size();
        fun(candidates,n,target,0,k,v);
        
        return v;
    }
    
    void fun(vector<int> candidates,int n,int target,int index,vector<int>& k,vector<vector<int>>& v){
        if(target==0){
            v.push_back(k);
            return;
        }
        if(target<0 || index>=n)
            return;
        
        //taking the element at index
        k.push_back(candidates[index]);
        fun(candidates,n,target-candidates[index],index,k,v);
        k.pop_back();   
        
        //not taking the element at index
        fun(candidates,n,target,index+1,k,v);
    }
};