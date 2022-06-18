class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n=s.length(),length=0;
        
        for(int i=0,j=0;i<n;i++){
            vector<int> v;
            for(int j=i;j<n;j++){
                if(!count(v.begin(),v.end(),s[j]))
                    v.push_back(s[j]);
                else
                    break;
            }
            if(v.size()>length)
                length=v.size();
        }
        return length;
    }
};