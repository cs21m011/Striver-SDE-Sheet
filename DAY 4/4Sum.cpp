class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n=nums.size();
        if(n<4)
            return {};
        
        vector<int> v;
        for(int i=0;i<n;i++)
            v.push_back(nums[i]);
        
        //sorting the array
        sort(v.begin(),v.end());
        
        vector<vector<int>> res;
        //first 3 pinters point to first 3 indiceos.4th pointer points to last inde
        int i=0,j=1,k=2,l=n-1;
        while(i<n-3){
            for(;k<l;){
                long p=v[i]+v[j]+v[k]+v[l];
                if(p==target){
                    res.push_back({v[i],v[j],v[k],v[l]});
                    
                    //loop is for avoiding the duplicates 
                    int temp=0;
                    for(temp=l-1;temp>k && v[l]==v[temp];temp--); 
                    l=temp;
                    for(temp=k+1;temp<n && v[k]==v[temp];temp++); 
                    k=temp; 
                }
                else if(p>target){
                    int temp=0;
                    //loop is for avoiding the duplicates  
                    for(temp=l-1;temp>k && v[l]==v[temp];temp--); 
                    l=temp;
                }
                else if(p<target){
                     int temp=0;
                    //loop is for avoiding the duplicates  
                    for(temp=k+1;temp<n && v[k]==v[temp];temp++); 
                    k=temp;  
                }
            }
            
            //quadraple with same first pointer.
            int temp;
            for(temp=j+1;temp<n && v[j]==v[temp];temp++); //avoiding duplicates
            j=temp;
            k=j+1;
            l=n-1;
            if(k==l || k>=n){
                //first pointer points to next non-duplicate index
                for(temp=i+1;temp<n && v[i]==v[temp];temp++); //avoiding duplicates
                i=temp;
                j=i+1;
                k=j+1;
                l=n-1;
            }
        }
        return res;
    }
};