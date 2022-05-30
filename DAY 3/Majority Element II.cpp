class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n=nums.size(),k=n/3;
        
        sort(nums.begin(),nums.end());
        
        //base cases
        if(n==1)
            return nums;
        if(n==2){
            if(nums[0]==nums[1])
                return {nums[0]};
            return nums;
        }
    
        vector<int> v;
        for(int i=0;i<n;){
             //comparing the element at i+k index
            if(i+k<n && nums[i+k]==nums[i] && !count(v.begin(),v.end(),nums[i])){
                v.push_back(nums[i]);
                i+=k;
            }
            else
                i++;
        }
        return v;
    }
};