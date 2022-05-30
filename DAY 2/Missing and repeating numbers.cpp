#include <bits/stdc++.h> 

pair<int,int> missingAndRepeating(vector<int> &arr, int n){
    unordered_map<int,int> umap;
    int miss=0,repeat=0;
    
    /* finding the repeating number */
    for(int i=0;i<n;i++)
        umap[arr[i]]++;
    //finding the frequency of numbers
    for(auto it:umap){
        if(it.second>1)
            repeat=it.first;  
    }
    
    /* finding the missing number */
    int missing[n]={0};
    for(int i=0;i<n;i++)
        missing[arr[i]-1]=1;
    for(int i=0;i<n;i++){
        if(missing[i]==0)
            miss=i+1;
    }
    
    return {miss,repeat};
}
