#include <bits/stdc++.h>

using namespace std;

void newSort(vector<int>&);
int findOddIndex(vector<int>&,int);
int findEvenIndex(vector<int>&,int);

int main(){
    vector<int> v={6,5,4,3,2};
    
    newSort(v);
    for(int i=0;i<v.size();i++){
        cout << v[i] << " ";
    }
    return 0;
}

void newSort(vector<int>& v){
    int n=v.size();
    
    //modifying the array such that odd numbers at even indices and even numbers at odd indices
    for(int i=0;i<n;i++){
        if(i%2==0 && v[i]%2==0){
            int k=findOddIndex(v,i);
            
            if(k<n){
                int temp=v[i];
                v[i]=v[k];
                v[k]=temp;
            }
        }
        
        if(i%2==1 && v[i]%2==1){
            int k=findEvenIndex(v,i);
            
            if(k<n){
                int temp=v[i];
                v[i]=v[k];
                v[k]=temp;
            }
        }
    }
    
    for(int pp=0;pp<n;pp++){
        int swap1=0,swap2=0;
        for(int i=0,j=1;i<n-2 && j<n-1;i+=2,j+=2){
            
            //odd numbers
            if(v[i]>v[i+2]){
                int temp=v[i];
                v[i]=v[i+2];
                v[i+2]=temp;
                
                swap1=1;
            }
            
            //even numbers
            if(v[j]<v[j+2]){
                int temp=v[j];
                v[j]=v[j+2];
                v[j+2]=temp;
                
                swap2=1;
            }
        }
        
        if(swap1==0 && swap2==0)
            break;   
    }
}

int findOddIndex(vector<int>& v,int i){
    for(int j=i+1;j<v.size();j++){
        if(v[j]%2==1)
            return j;
    }
    return v.size();
}

int findEvenIndex(vector<int>& v,int i){
    for(int j=i+1;j<v.size();j++){
        if(v[j]%2==0)
            return j;
    }
    return v.size();
}
