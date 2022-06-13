class Solution {
public:
    bool isAnagram(string s, string t) {
        int m=s.length(),n=t.length();
        if(m!=n)
            return false;
        
        //finding the frequencies of characters in both the strings
        unordered_map<char,int> m1,m2;
        for(int i=0;i<m;i++){
            m1[s[i]]++;
            m2[t[i]]++;
        }
        
        //comparing the frequencies
        for(auto x:m1){
            int k=0;
            for(auto y:m2){
                if(x.first==y.first){
                    if(x.second!=y.second)
                        return false;
                    k=1;
                }
            }
            if(k==0)
                return false;
        }
        return true;
    }
};