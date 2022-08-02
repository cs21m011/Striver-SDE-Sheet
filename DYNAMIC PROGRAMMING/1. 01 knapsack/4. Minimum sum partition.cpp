//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{

public:
    int minDifference(int arr[], int n){ 
	    int sum=0;
	    for(int i=0;i<n;i++)
	        sum+=arr[i];
	        
	    vector<vector<bool>> dp(n+1,vector<bool>(sum+1,false));
        //initialization
	    for(int i=0;i<=sum;i++)
	        dp[0][i]=false;
	    for(int i=0;i<=n;i++)
	        dp[i][0]=true;
	        
	    //actual code
	    for(int i=1;i<=n;i++){
	        for(int j=1;j<=sum;j++){
	            if(arr[i-1]<=j)
	                dp[i][j]=dp[i-1][j] || dp[i-1][j-arr[i-1]];
	            else
	                dp[i][j]=dp[i-1][j];
	        }
	    }
	    
	    //finding the difference
        int res=sum;
    	for(int i=1;i<=sum/2;i++){
    	    if(dp[n][i]==true){
    	        if((sum-2*i)<res)
    	            res=sum-2*i;
    	    }
    	}
	    return res;
    } 
};


//{ Driver Code Starts.
int main() 
{
   
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        int a[n];
        for(int i = 0; i < n; i++)
        	cin >> a[i];

       

	    Solution ob;
	    cout << ob.minDifference(a, n) << "\n";
	     
    }
    return 0;
}
// } Driver Code Ends