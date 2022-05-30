class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {        
        
        for(int i=0,j=0;i<m && n>0;i++){
            if(nums1[i]>nums2[j]){
                int temp=nums1[i];
                nums1[i]=nums2[j];
                nums2[j]=temp;
                
            //sorting the second array to make it always sorted incase of swap.
                sort(nums2,n);
            }
        }
        
        //merging the nums2 array into nums1
        for(int i=m,j=0;i<m+n && n>0;i++,j++)
            nums1[i]=nums2[j];
    }
    
    void sort(vector<int>& nums2,int n){
        for(int i=0;i<n;i++){
            int swap=0;
            for(int j=0;j<n-i-1;j++){
                if(nums2[j]>nums2[j+1]){
                    int temp=nums2[j];
                    nums2[j]=nums2[j+1];
                    nums2[j+1]=temp;
                    
                    swap=1;
                }
            }
            if(swap==0)
                break;
        }   
    }
};