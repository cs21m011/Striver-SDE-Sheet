class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n=nums.size(),index1=-1,index2=-1;
        
        //finding the index1.
        for(int i=n-2;index1==-1 && i>=0;i--){
            if(nums[i]<nums[i+1])
                index1=i;
        }
        
        //finding the index2
        for(int i=n-1;index2==-1 && i>=0;i--){
            if(index1!=-1 && nums[i]>nums[index1])
                index2=i;
        }
        
        //reversing
        if(index1!=-1 && index2!=-1){
            int temp=nums[index1];
            nums[index1]=nums[index2];
            nums[index2]=temp;
        }
        for(int i=index1+1,j=n-1;i<j;i++,j--){
            int temp=nums[i];
            nums[i]=nums[j];
            nums[j]=temp;
        }
    }
};

vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n=intervals.size();
        vector<vector<int>> v;
        
        for(int i=0,j=0;i<n;){
            vector<int> k;
            int merged=0;
            for(j=i+1;j<n;j++){
                if(intervals[i][1]>=intervals[j][0] && intervals[j][1]>=intervals[i][0]){
                    k.push_back(intervals[i][0]);
                    k.push_back(intervals[j][1]);
                    
                    merged=1;
                }
                else
                    break;
            }
            
            if(merged==0)
                v.push_back({intervals[i][0],intervals[i][1]});
            else{
                int s=k.size();
                v.push_back({k[0],k[s-1]});
            }
            i=j;
        }
        return v;
    }