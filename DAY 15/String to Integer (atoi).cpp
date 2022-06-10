class Solution {
public:
    int myAtoi(string s) {
        int n=s.length();
        long long num=0,neg=0,pos=0;
        
        for(int i=0;i<n;i++){
             //converting characters into number
            if((int)s[i]>=48 && (int)s[i]<=57){
                int k=(int)s[i]-48;
                num=num*10+k;
                
                if(num<=INT_MIN || num>=INT_MAX)
                    break;
            }
            
            //checking for characters at front of the string
            else if((((int)s[i]>=65 && (int)s[i]<=90) || ((int)s[i]>=97 && (int)s[i]<=122)) && num==0)
                return 0;
            else if(s[i]=='-')
                neg=-1;
            else if(s[i]=='+')
                pos=1;
            else if(s[i]==' ')
                continue;
            else 
                break;
        }
        
        if(neg==-1 && pos==1)
            return 0;
        if(neg==-1)
            num=-1*num;
        
        if(num<=INT_MIN)
            return INT_MIN;
        if(num>=INT_MAX)
            return INT_MAX;
        return (int)num;
    }
};