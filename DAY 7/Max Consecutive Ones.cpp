class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int len=nums.size(),res=0,ones_length=0;
        
        for(int i=0;i<len;i++){
            if(nums[i]==1)
                ones_length++;
            else
                ones_length=0;
                
            if(ones_length>res)
                res=ones_length;
        }
        return res;
    }
};