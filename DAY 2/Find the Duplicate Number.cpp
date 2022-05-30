class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        unordered_map<int,int> umap;
        
        //finding the frequency of each number
        for(int i=0;i<nums.size();i++)
            umap[nums[i]]++;
        
        //checking the frequency for greater than 1 
        for(auto it:umap){
            if(it.second>1)
                return it.first;
        }
        return -1;
    }
};