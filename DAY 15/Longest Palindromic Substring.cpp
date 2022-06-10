class Solution {
public:
    string longestPalindrome(string s) {
        int n=s.length(),res=1,start=0;
        int dp[n][n];
        
        //filling one length and 2 length strings
        for(int i=0;i<n;i++)
            dp[i][i]=1;
        for(int i=0;i<n-1;i++){
            if(s[i]==s[i+1]){
                dp[i][i+1]=1;
                start=i;
                res=2;
            }
            else
                dp[i][i+1]=0;
        }
        
        for(int k=3;k<=n;k++){
            for(int i=0;i<n-k+1;i++){
                int j=i+k-1;
                if(s[i]==s[j] && dp[i+1][j-1]==1){
                    dp[i][j]=1;
                    
                    if(k>res){
                        start=i;
                        res=k;
                    }
                }
                else
                    dp[i][j]=0;
            }
        }
        
        string p="";
        for(int i=start;i<start+res;i++)
            p=p+s[i];
        return p;
    }
};