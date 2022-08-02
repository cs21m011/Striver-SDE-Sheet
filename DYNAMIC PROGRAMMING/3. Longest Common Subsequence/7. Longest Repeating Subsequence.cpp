//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
	public:
	int LongestRepeatingSubsequence(string X){
	    string Y=X;
	    int n=X.length();
        
        vector<vector<int>> dp(n+1,vector<int>(n+1,-1));
       //initialization
        for(int i=0;i<=n;i++)
            dp[i][0]=0;
        for(int i=0;i<=n;i++)
            dp[0][i]=0;
            
        
        //actual code
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(X[i-1]==Y[j-1] && i!=j)
                    dp[i][j]=dp[i-1][j-1]+1;
                else
                    dp[i][j]=max(dp[i][j-1],dp[i-1][j]);
            }
        }
        return dp[n][n];
	}

};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string str;
		cin >> str;
		Solution obj;
		int ans = obj.LongestRepeatingSubsequence(str);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends