
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n=nums.size(),k=n/2;
        sort(nums.begin(),nums.end());
        
        for(int i=0;i<n;i++){
            //comparing the element at i+k index
            if(nums[i+k]==nums[i])
                return nums[i];
        }
        return -1;
    }
};