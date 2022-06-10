class Solution {
public:
    int findKthLargest(vector<int>& nums, int k){
        int n=nums.size(),start=n/2-1;
        
        //heapifying the array
        for(int i=start;i>=0;i--)
            heapify(nums,n,i);
        
        for(int p=1;p<k;p++){
            extract_min(nums,n);
            n--;
        }
        return nums[0];
    }
    
    void extract_min(vector<int>& nums,int n){
        nums[0]=nums[n-1];
        n--;
        int start=n/2-1;
        for(int i=start;i>=0;i--)
            heapify(nums,n,i);
    }
    
    void heapify(vector<int>& nums,int n,int i){
        int largest=i;
        int left=2*i+1,right=2*i+2;
        
        if(left<n && nums[left]>nums[largest])
            largest=left;
        if(right<n && nums[right]>nums[largest])
            largest=right;
        
        if(largest!=i){
            int temp=nums[largest];
            nums[largest]=nums[i];
            nums[i]=temp;
            
            heapify(nums,n,largest);
        }
    }
};