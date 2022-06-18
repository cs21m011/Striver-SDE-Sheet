class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
        sudokuSolver(board);
    }
    
    bool sudokuSolver(vector<vector<char>>& board){
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                if(board[i][j]=='.'){
                    for(char k='1';k<='9';k++){
                        if(possible(board,k,i,j)){
                            board[i][j]=k;
                        
                            if(sudokuSolver(board))
                                return true;
                            else
                                board[i][j]='.'; //if previously assignde value is false
                        }
                    }
                    return false;
                }
            }
        }
        return true;
    }
    
    bool possible(vector<vector<char>>& board,char k,int i,int j){
        for(int p=0;p<9;p++){
            //checking in row
            if(board[i][p]==k)
                return false;
            
            //checking in column
            if(board[p][j]==k)
                return false;
            
            //checking in 3x3 cube
            if(board[3*(i/3)+p/3][3*(j/3)+p%3]==k)
                return false;
        }
       
        /*
        //checking in row
        for(int p=0;p<9;p++){
            if(board[i][p]==k)
                return false;
        }
        
        //checking in column
        for(int p=0;p<9;p++){
            if(board[p][j]==k)
                return false;
        }
        
        //checking in 3x3 cube
        int p=(p%3==0)?i:((p%2==1)?i-1:i-2); //getting the starting row number
        int q=(q%3==0)?j:((q%2==1)?j-1:j-2); //getting the starting column number
        
        for(int p1=p;p1<(p+3);p1++){
            int q1=q;
            for(;q1<(q+3);q1++){
                if(board[p1][q1]==k)
                    return false;
            }
        }*/
        
        return true;
    }
};