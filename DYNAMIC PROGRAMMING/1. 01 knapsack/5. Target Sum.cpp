//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//Back-end complete function Template for C++

class Solution {
  public:
    int findTargetSumWays(vector<int>&A ,int target) {
        int sum=0,n=A.size();
        for(int i=0;i<n;i++)
            sum+=A[i]; 
            
        int k=(sum+target)/2;
        vector<vector<int>> dp(n+1,vector<int>(k+1,-1));
        //initialization
        for(int i=0;i<=k;i++)
            dp[0][i]=0;
        for(int i=0;i<=n;i++)
            dp[i][0]=1;
            
        //actual code
        for(int i=1;i<=n;i++){
            for(int j=1;j<=k;j++){
                if(A[i-1]<=j)
                    dp[i][j]=dp[i-1][j]+dp[i-1][j-A[i-1]];
                else
                    dp[i][j]=dp[i-1][j];
            }
        }
        return dp[n][k];
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        
        cin>>N;
        vector<int>arr(N);
        
        for(int i=0 ; i<N ; i++){
            cin>>arr[i];
        }
        int target;
        cin >> target;

        Solution ob;
        cout<<ob.findTargetSumWays(arr,target);
        cout<<"\n";
    }
    return 0;
}
// } Driver Code Ends