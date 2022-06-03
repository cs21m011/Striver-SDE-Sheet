class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> v;
        vector<string> k;
        
        int n=s.length();
        fun(s,n,0,k,v);
        return v;
    }
    
    void fun(string s,int n,int index,vector<string>& k,vector<vector<string>>& v){
        if(index>=n){
            v.push_back(k);
            return;
        }
        
        for(int i=index;i<n;i++){
            if(palindrome(s,index,i)){
                k.push_back(s.substr(index,i-index+1));
                fun(s,n,i+1,k,v);
                k.pop_back();
            }
        }
    }
    
    bool palindrome(string s,int start,int end){
        for(int i=start,j=end;i<j;i++,j--){
            if(s[i]!=s[j])
                return false;
        }
        return true;
    }
};