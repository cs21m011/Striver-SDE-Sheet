class Solution {
public:
    int repeatedStringMatch(string a, string b) {
        int count=1;
        
        string temp=a;
        while(b.length()>a.length()){
            //checking whether string b is a substring of a or not 
            a=a+temp;
            count++;
        }
        
        if(substring(a,b))
            return count;
        if(substring(a+temp,b))
            return count+1;
        return -1;
    }
    
    bool substring(string a,string b){
        int k=a.find(b);
        
        if(k>=0)
            return true;
        return false;
    }
};