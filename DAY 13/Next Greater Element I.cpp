class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int m=nums1.size(),n=nums2.size();
        
        stack<int> s;
        int arr[n];
        for(int i=n-1;i>=0;i--){
            //no greater element exists to the right of last element
            if(i==n-1){
                arr[i]=-1;
                s.push(nums2[i]);
            }
            else{
                //if stack top is greater, then it is greater element to the right
                if(s.top()>nums2[i])
                    arr[i]=s.top();
                //else pop elements until greater element is found
                else{
                    while(!(s.empty()) && s.top()<=nums2[i])
                        s.pop();
                    
                    if(s.empty())
                        arr[i]=-1;
                    else
                        arr[i]=s.top();
                }
                s.push(nums2[i]);
            }
        }
        
        vector<int> v;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(nums1[i]==nums2[j])
                    v.push_back(arr[j]);
            }
        }
        return v;
    }
};