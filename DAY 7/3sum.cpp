class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {

        sort(nums.begin(),nums.end());
        
        int n=nums.size();
        vector<vector<int>> v;
        for(int i=0;i<n-2;){
            for(int j=i+1,k=n-1;j<k;){
                int sum=nums[i]+nums[j]+nums[k];
                if(sum==0){
                    v.push_back({nums[i],nums[j],nums[k]});
                    
                    //avoiding duplicate values for j
                    int p=j+1;
                    for(;p<n && nums[p]==nums[j];p++);
                    j=p;
                    
                    //avoiding duplicate values for j
                    p=k-1;
                    for(;p>0 && nums[p]==nums[k];p--);
                    k=p;
                }
                else if(sum<0){
                    //avoiding duplicate values for j
                    int p=j+1;
                    for(;p<n && nums[p]==nums[j];p++);
                    j=p;
                }
                else if(sum>0){
                    //avoiding duplicate values for k
                    int p=k-1;
                    for(;p>0 && nums[p]==nums[k];p--);
                    k=p;
                }
            }
            
            int p=i+1;
            for(;p<n && nums[p]==nums[i];p++);
            i=p;
        }
        return v;
    }
    
    bool find(vector<vector<int>> v,int p,int q,int r){
        int n=v.size();
        
        for(int i=0;i<n;i++){
            if(v[i][0]==p && v[i][1]==q && v[i][2]==r)
                return true;
        }
        return false;
    }
};