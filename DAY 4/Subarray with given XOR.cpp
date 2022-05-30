#include <bits/stdc++.h> 

int subarraysXor(vector<int> &A, int B){
    //    Write your code here.
    int n=A.size(),xr=0,count=0;
    unordered_map<int,int> umap;
    for(int i=0;i<n;i++){
        xr=xr^A[i];
        
        if(xr==B)
            count++;
        if(umap[xr^B]>0)
            count=count+umap[xr^B];
        umap[xr]++;
    }
    if(count==0)
        return 1;
    return count;
}