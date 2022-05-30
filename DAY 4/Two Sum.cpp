class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target){
        vector<int> v;
        for(int i=0,n=nums.size();i<n;i++)
            v.push_back(nums[i]);
        
        sort(v.begin(),v.end());
        
        for(int i=0,j=nums.size()-1;i<j;){
            if(v[i]+v[j]==target)
                return getIndices(nums,i,j,v);
            else if(v[i]+v[j]>target)
                j--;
            else if(v[i]+v[j]<target)
                i++;
        }
        return {-1,-1};
    }
    
    vector<int> getIndices(vector<int> nums,int i,int j,vector<int> v){
        int index1=-1,index2=-1,n=nums.size();
        
        //finding the indices in nums vector
        for(int k=0;k<n;k++){
            if(nums[k]==v[i] && index1==-1)
                index1=k;
            else if(nums[k]==v[j] && index2==-1)
                index2=k;
            
            if(index1!=-1 && index2!=-1){
                vector<int> ind;
                ind.push_back(index1);
                ind.push_back(index2);
                sort(ind.begin(),ind.end());
                return ind;
            }
        }
        return {-1,-1};
    }
};