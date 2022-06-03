class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> v;
        vector<int> k;
        
        int n=candidates.size();
        sort(candidates.begin(),candidates.end());
        fun(candidates,target,n,0,k,v);
        return v;
    }
    
    void fun(vector<int> candidates,int target,int n,int index,vector<int>& k,vector<vector<int>>& v){
        if(target==0){
            v.push_back(k);
            return;
        }
        if(index>=n || target<0)
            return;
        

        for(int i=index;i<n;i++){
            //taking the element
            if(index==i || candidates[i]!=candidates[i-1]){
                k.push_back(candidates[i]);
                fun(candidates,target-candidates[i],n,i+1,k,v);
                k.pop_back();
            }
        }
    }
};