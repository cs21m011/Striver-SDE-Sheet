class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> queen;
        vector<string> temp;
        string s(n,'.');
        for(int i=0;i<n;i++)
            temp[i]=s;
        
        solver(queen,n,0,temp);
        
        return queen;
    }
    
    void solver(vector<vector<string>>& queen,int n,int j,vector<string>& temp){
        if(j>=n){
            queen.push_back(temp);
            return;
        }
        
        for(int i=0;i<n;i++){
            if(isPossible(temp,i,j,n)){
                temp[i][j]='Q';
                solver(queen,n,j+1,temp);
                temp[i][j]='.';
            }
        }
    }
    
    bool isPossible(vector<string>& temp,int i,int j,int n){
        
        //checking the left side queen
        for(int k1=j;k1>=0;k1--){
            if(temp[i][k1]=='Q')
                return false;
        }
        
        //checking the lower diagonal queen
        for(int k1=i,k2=j;k1<n && k2>=0;k1++,k2--){
            if(temp[k1][k2]=='Q')
                return false;
        }
        
        //checking the upper diagonal queen
        for(int k1=i,k2=j;k1>=0 && k2>=0;k1--,k2--){
            if(temp[k1][k2]=='Q')
                return false;
        }
        
        return true;
    }
};