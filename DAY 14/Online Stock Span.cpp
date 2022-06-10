#include <bits/stdc++.h>

vector<int> findSpans(vector<int> &price) {
    // Write your code here.
    int n=price.size();
    vector<int> v;
    v.push_back(1);
    
    stack<int> s;
    s.push(0);
    for(int i=1;i<n;i++){
        while(!s.empty() && price[s.top()]<=price[i])
            s.pop();
       
        if(s.empty())
            v.push_back(i+1);
        else
            v.push_back(i-s.top());
        
        s.push(i);
    }
    return v;
}