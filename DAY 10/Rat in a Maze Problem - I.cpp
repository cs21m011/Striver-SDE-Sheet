// { Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// User function template for C++

void solver(vector<string>&,vector<vector<int>>&,int,int,string,vector<vector<int>>&,int);

class Solution{
    public:
    vector<string> findPath(vector<vector<int>> &m, int n) {
        vector<vector<int>> visited(n,vector<int>(n,0));
        vector<string> ans;
        
        solver(ans,visited,0,0,"",m,n);
        return ans;
    } 
    
    void solver(vector<string>& ans,vector<vector<int>>& visited,int i,int j,string move,vector<vector<int>>& m,int n){
        if(i==n-1 && j==n-1){
            ans.push_back(move);
            return;
        }      
        
        //check for left cell
        if(j>0 && m[i][j-1]!=0 && visited[i][j-1]==0){
            visited[i][j]=1;
          
            solver(ans,visited,i,j-1,move+'L',m,n);
            
            visited[i][j]=0;
        }
        
        //check for right cell
        if(m[i][j+1]!=0 && visited[i][j+1]==0){
            visited[i][j]=1;

            solver(ans,visited,i,j+1,move+'R',m,n);
            
            visited[i][j]=0;
        }
        
        //check for top cell
        if(i>0 && m[i-1][j]!=0 && visited[i-1][j]==0){
            visited[i][j]=1;

            solver(ans,visited,i-1,j,move+'U',m,n);
            
            visited[i][j]=0;
        }
        
        //check for down cell
        if(i<n-1 && m[i+1][j]!=0 && visited[i+1][j]==0){
            visited[i][j]=1;

            solver(ans,visited,i+1,j,move+'D',m,n);
            
            visited[i][j]=0;
        }
    }
};

    


// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> m(n, vector<int> (n,0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> m[i][j];
            }
        }
        Solution obj;
        vector<string> result = obj.findPath(m, n);
        sort(result.begin(), result.end());
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++) cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}  // } Driver Code Ends