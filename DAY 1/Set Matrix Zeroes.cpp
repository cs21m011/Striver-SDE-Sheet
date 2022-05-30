class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m=matrix.size(),n=matrix[0].size(),called=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(matrix[i][j]==0){
                    modify_matrix(matrix,i,j);
                    called=1;
                }
            }
        }
        
        // changing infinity to 0
        if(called==1){
            for(int i=0;i<m;i++){
                for(int j=0;j<n;j++){
                    if(matrix[i][j]==INT_MAX-1)
                        matrix[i][j]=0;
                }
            }
        }
    } 
    
    void modify_matrix(vector<vector<int>>& matrix,int i,int j){
        int m=matrix.size(),n=matrix[0].size();
        
        //for filling infinity along the row
        for(int ii=0;ii<n;ii++){
            if(matrix[i][ii]!=0)    
                matrix[i][ii]=INT_MAX-1;
        }
        
        //for filling the infinity along the column
        for(int jj=0;jj<m;jj++){
            if(matrix[jj][j]!=0)
                matrix[jj][j]=INT_MAX-1;
        }
    }
};