class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m=matrix.size(),n=matrix[0].size();
        
        for(int i=0;i<m;i++){
            for(int j=0;j<n;){
                if(target==matrix[i][j])
                    return 1;
                //if target is in same row
                else if(target<=matrix[i][n-1])
                    j++;
                //if target is in next row
                else if(target>=matrix[i][n-1])
                    j=n;
            }
        }
        return 0;
    }
};