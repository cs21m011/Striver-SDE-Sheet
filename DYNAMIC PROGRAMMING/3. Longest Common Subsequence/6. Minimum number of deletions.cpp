//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
int minDeletions(string str, int n);

int main(){
    int t;
    cin >> t;
    while(t--){
        
        int n;
        cin >> n;
        string s;
        cin >> s;
        cout << minDeletions(s, n) << endl;

    }
return 0;
}
// } Driver Code Ends


int minDeletions(string X, int n) { 
    string Y="";
    for(int i=n-1;i>=0;i--)
        Y+=X[i];
        
        
    vector<vector<int>> dp(n+1,vector<int>(n+1,-1));
   //initialization
    for(int i=0;i<=n;i++)
        dp[i][0]=0;
    for(int i=0;i<=n;i++)
        dp[0][i]=0;
        
    
    //actual code
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(X[i-1]==Y[j-1])
                dp[i][j]=dp[i-1][j-1]+1;
            else
                dp[i][j]=max(dp[i][j-1],dp[i-1][j]);
        }
    }
    return n-dp[n][n]; 
} 