class Solution {
public:
    int strStr(string haystack, string needle) {
        if(needle=="")
            return 0;
        
        int res=haystack.find(needle);
        
        if(res>=0)
            return res;
        return -1;
    }
};