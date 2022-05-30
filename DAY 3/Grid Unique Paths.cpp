class Solution {
public:
    int uniquePaths(int m, int n) {
        if(m==1 && n==1)
            return 1;
        
        //initilalizing dp matrix
        vector<vector<int>> dp(m,vector<int>(n,-1));
                
        dp[m-1][n-1]=1;
        return getPaths(0,0,m,n,dp);
    }
    
    //dynamic programming
    int getPaths(int i,int j,int m,int n,vector<vector<int>>& dp){
        if(i>=m || j>=n)
            return 0;
        if(i==m-1 && j==n-1)
            return 1;
        
        //checking the subproblem is already solved or not
        if(dp[i][j]==-1){
            int right=getPaths(i,j+1,m,n,dp);
            int down=getPaths(i+1,j,m,n,dp);
            
            dp[i][j]=right+down;
        }
        return dp[i][j];
    }
    
    /* //recurisve solution
    int getPaths(int i,int j,int m,int n){
        if(i>=m || j>=n)
            return 0;
        if(i==m-1 && j==n-1)
            return 1;
        
        int right=getPaths(i,j+1,m,n);
        int down=getPaths(i+1,j,m,n);
        
        return right+down;
    }*/
};