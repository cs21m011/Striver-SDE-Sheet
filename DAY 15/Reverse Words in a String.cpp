class Solution {
public:
    string reverseWords(string s) {
        s=trimString(s);
        int n=s.length(),k=0;
        string res="",temp="";
        
        for(int i=n-1;i>=0;i--){
            //insert the word until space
            if(s[i]!=' ')
                temp=s[i]+temp;
            //if space occured, insert he word into final result string
            else if(temp.length()>0){
                if(res.length()==0)
                    res=res+temp;
                else
                    res=res+" "+temp;
                
                temp="";
                k=1;
            }
        }
        
        //for multi word string for inserting first word
        if(temp.length()>0 && k==1)
            res=res+" "+temp;
        //for single word string
        else
            res=res+temp;
             
        return res;
    }
    
    string trimString(string s){
        int n=s.length(),start=0,end=n-1;
        
        for(;s[start]==' ';start++);
        for(;s[end]==' ';end--);
        
        string p="";
        for(int i=start;i<=end;i++)
            p=p+s[i];
        return p;
    }
};