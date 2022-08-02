//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
	public:
	int minOperations(string X, string Y) { 
	   int m=X.length(),n=Y.length();
	   
	   vector<vector<int>> dp(m+1,vector<int>(n+1,-1));
	   //initialization
        for(int i=0;i<=m;i++)
            dp[i][0]=0;
        for(int i=0;i<=n;i++)
            dp[0][i]=0;
            
        
        //actual code
        for(int i=1;i<=m;i++){
            for(int j=1;j<=n;j++){
                if(X[i-1]==Y[j-1])
                    dp[i][j]=dp[i-1][j-1]+1;
                else
                    dp[i][j]=max(dp[i][j-1],dp[i-1][j]);
            }
        }
        
        int deletions=m-dp[m][n],insertions=n-dp[m][n];
        return deletions+insertions;
	} 
};

//{ Driver Code Starts.
int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        string s1, s2;
        cin >> s1 >> s2;

	    Solution ob;
	    cout << ob.minOperations(s1, s2) << "\n";
	     
    }
    return 0;
}


// } Driver Code Ends