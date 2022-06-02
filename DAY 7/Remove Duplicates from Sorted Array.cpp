class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n=nums.size(),i=0,j=0,actual_len=0;
        
        for(int l=0;l<n;l++){
            int modified=0;
            //skipping all the unique elements
            for(;i<n-1 && nums[i]!=nums[i+1];i++);

            //after finding the same element twice, skipping the element completely
            for(j=i+1;j<n && nums[i]==nums[j];j++);

            //replacing the elements
            for(int k=i+1;j<n;k++,j++){
                nums[k]=nums[j];   
                modified=1;
            }
            
            //if no element is modified, it means no duplicates
            if(modified==0)
                l=n;
        }
        
        //finding the length of vector of unique elements
        for(i=0,j=1;j<n && nums[i]!=nums[j] && nums[i]<nums[j];i++,j++);
        return j;
    }
};