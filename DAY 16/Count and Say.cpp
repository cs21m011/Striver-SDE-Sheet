class Solution {
public:
    string countAndSay(int n) {
        if(n==1)
            return "1";
        if(n==2)
            return "11";
        
        string res="11",temp="";
        for(int i=3;i<=n;i++){
            temp=res;
            res="";
            int len=temp.length();
            
            //counting the no. of occurences of each character
            for(int j=0,k=0;j<len;){
                for(k=j+1;k<len && temp[j]==temp[k];k++);
                
                res=res+to_string(k-j)+temp[j];
                j=k;
            }
        }
        return res;
    }
};