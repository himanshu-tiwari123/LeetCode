class Solution {
    int n;
    vector<vector<char>>ans;
    bool canPlace(int row,int col,char val,vector<vector<char>>& board){
        
        for(int i=0;i<9;i++){
            if(board[row][i] == val) return false;

            if(board[i][col] == val) return false;
        }
        

        int row1=row/3,col1=col/3;

        row1 *=3,col1*=3;

        for(int i=row1;i<row1+3;i++){
            for(int j=col1;j<col1+3;j++){
                if(board[i][j] == val){
                    return false;
                }
            }
        } 

        return true;

    }

    bool findAns(int row,int col,vector<vector<char>>& board){
        if(row >= n){
           return true;
        }
        if(col>=n){
            return findAns(row+1,0,board);
        }
        if(board[row][col]!='.'){
            return findAns(row,col+1,board);
        }

        for(char val='1';val<='9';val++){
           if(canPlace(row,col,val,board)){
                board[row][col] =val;

                if(findAns(row,col+1,board)) return true;

                board[row][col] ='.';

           }
        }

        return false;
    }

public:
    void solveSudoku(vector<vector<char>>& board) {
        n = board.size();
       
       findAns(0,0,board);

    }
};