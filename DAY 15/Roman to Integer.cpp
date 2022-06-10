class Solution {
public:
    int romanToInt(string s) {
        int n=s.length(),res=0;
        
        for(int i=0;i<n;i++){
            if(s[i]=='I')
                res=res+1;
            else if(s[i]=='V'){
                res=res+5;
                if(i>0 && s[i-1]=='I')
                    res=res-2;
            }
            else if(s[i]=='X'){
                res=res+10;
                if(i>0 && s[i-1]=='I')
                    res=res-2;
            }
            else if(s[i]=='L'){
                res=res+50;
                if(i>0 && s[i-1]=='X')
                    res=res-20;
            }
            else if(s[i]=='C'){
                res=res+100;
                if(i>0 && s[i-1]=='X')
                    res=res-20;
            }
            else if(s[i]=='D'){
                res=res+500;
                if(i>0 && s[i-1]=='C')
                    res=res-200;
            }
            else if(s[i]=='M'){
                res=res+1000;
                if(i>0 && s[i-1]=='C')
                    res=res-200;
            }
        }
        return res;
    }
};