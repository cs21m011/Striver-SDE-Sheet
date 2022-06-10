#include <bits/stdc++.h>

vector<int> nextSmallerElement(vector<int> &arr, int n){
    // Write your code here.
    int temp[n];
    stack<int> s;
    
    for(int i=n-1;i>=0;i--){
        if(i==n-1){
            temp[n-1]=-1;
            s.push(arr[i]);
        }
        else{
            if(s.top()<arr[i])
                temp[i]=s.top();
            else{
                while(!s.empty() && s.top()>=arr[i])
                    s.pop();
                
                if(s.empty())
                    temp[i]=-1;
                else
                    temp[i]=s.top();
            }
            s.push(arr[i]);
        }
    }
    
    vector<int> v;
    for(int i=0;i<n;i++)
        v.push_back(temp[i]);
    
    return v;
}