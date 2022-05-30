class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        
        int n=nums.size();
        if(n==0 || n==1)
            return n;
        if(n==2){
            if(nums[0]==nums[1])
                return 1;
        }
        
        int start=0,end=1,res=1; //res=1 because every number is contiguos
        for(int i=0,j=1;i<n-1;i++,j++){
            if(nums[j]-nums[i]==1){
                end++;
                if((end-start)>res)
                    res=end-start;
            }
            else if(nums[j]-nums[i]==0){
                start++;
                end++;
            }
            else if(nums[j]-nums[i]>1){
                start=j;
                end=j+1;
            }
        }
        return res;
    }
};