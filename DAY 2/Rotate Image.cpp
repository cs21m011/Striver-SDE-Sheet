class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int m=matrix.size(),n=matrix[0].size();
        
        for(int i=0;i<m;i++){
            //transposing the matrix
            for(int j=0;j<n;j++){
                if(i<j){
                    int temp=matrix[i][j];
                    matrix[i][j]=matrix[j][i];
                    matrix[j][i]=temp;
                }
            }
            
            //reversing the row    
            reverse_row(matrix,i);
        }
    }
    
    void reverse_row(vector<vector<int>>& matrix,int i){
        for(int j=0,k=matrix[i].size()-1;j<k;j++,k--){
            int temp=matrix[i][j];
            matrix[i][j]=matrix[i][k];
            matrix[i][k]=temp;
        }
    }
};