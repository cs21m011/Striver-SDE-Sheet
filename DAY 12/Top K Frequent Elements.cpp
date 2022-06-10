class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> umap;
        //storing the frequencies of each number
        for(int i:nums)
            umap[i]++;
        
        //forming the heap
        vector<vector<int>> p;
        for(auto x:umap)
            p.push_back({x.first,x.second});
        
        //converting the heap to max-heap based on the frequencies
        int n=p.size(),start=n/2-1;
        for(int i=start;i>=0;i--)
            heapify(p,n,i);
        
        //extract max element for k times
        vector<int> res;
        for(int q=1;q<=k;q++){
            res.push_back(p[0][0]);
            extract_min(p,n);
            n--;
        }
        return res;
    }
    
    void extract_min(vector<vector<int>>& p,int n){
        p[0][0]=p[n-1][0];
        p[0][1]=p[n-1][1];
        n--;
        
        int start=n/2-1;
        for(int i=start;i>=0;i--)
            heapify(p,n,i);
    }
    
    void heapify(vector<vector<int>>& p,int n,int i){
        int largest_freq=i;
        int left=2*i+1,right=2*i+2;
        
        if(left<n && p[left][1]>p[largest_freq][1])
            largest_freq=left;
        if(right<n && p[right][1]>p[largest_freq][1])
            largest_freq=right;
        
        if(largest_freq!=i){
            int temp=p[largest_freq][1];
            p[largest_freq][1]=p[i][1];
            p[i][1]=temp;
            
            temp=p[largest_freq][0];
            p[largest_freq][0]=p[i][0];
            p[i][0]=temp;
            
            heapify(p,n,largest_freq);
        }
    }
};