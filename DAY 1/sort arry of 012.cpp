class Solution {
public:
    void sortColors(vector<int>& nums) {
        int zero_count=0,one_count=0,two_count=0;
        
        for(int i=0;i<nums.size();i++){
            if(nums[i]==0)
                zero_count++;
            else if(nums[i]==1)
                one_count++;
            else if(nums[i]==2)
                two_count++;
        }
        
        one_count+=zero_count;
        two_count+=one_count;
        for(int i=0;i<nums.size();i++){
            if(i<zero_count)
                nums[i]=0;
            else if(i<one_count)
                nums[i]=1;
            else if(i<two_count)
                nums[i]=2;
        }
    }
};