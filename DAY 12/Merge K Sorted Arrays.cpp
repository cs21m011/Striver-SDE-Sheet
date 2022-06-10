#include <bits/stdc++.h>
vector<int> mergeKSortedArrays(vector<vector<int>>&kArrays, int k){
    // Write your code here. 
    vector<int> res;
    for(int counter=0;counter<k;counter++){
        vector<int> t;
        for(int i=0;i<kArrays[counter].size();i++)
            t.push_back(kArrays[counter][i]);
        
        counter++;
        if(counter==k){
            for(int w=0;w<t.size();w++)
                res.push_back(t[w]);
            break;
        }
        
        int i=0,j=0;
        int m=t.size(),n=kArrays[counter].size();
        
        while(i<m && j<n){
            if(t[i]<kArrays[counter][j]){
                res.push_back(t[i]);
                i++;
            }
            else if(t[i]>kArrays[counter][j]){
                res.push_back(kArrays[counter][j]);
                j++;
            }
            else{
                res.push_back(kArrays[counter][j]);
                res.push_back(t[i]);
                i++;
                j++;
            }
        }
        
        while(i<m){
            res.push_back(t[i]);
            i++;
        }
        while(j<n){
            res.push_back(kArrays[counter][j]);
            j++;
        }
    }
    sort(res.begin(),res.end());
    return res;
}
