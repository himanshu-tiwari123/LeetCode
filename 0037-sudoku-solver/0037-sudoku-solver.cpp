class Solution {
    bool isValid(int i,int j,int val,vector<vector<char>>& board){
    
        for(int l=0;l<9;l++){
            if(board[i][l]==(val+'0')){
                return false;
            }

            if(board[l][j] == (val+'0')) return false;
        }

        // unordered_map<int,pair<int,int>>a,b;
        // a[0]={0,2},a[1]={3,5},a[2] = {6,8};
        // b[0]={0,2},b[1]={3,5},b[2] = {6,8};
        // int x = i/3,y=j/3;

        // int l1,r1,l2,r2;
        // l1=a[x].first;r1=b[y].first;
        // l2=a[x].second;r2 = b[y].second;

        // for(int o=l1;o<=l2;o++){
        //     for(int p=r1;p<=r2;p++){
        //         if(board[o][p] == (val+'0')){
        //             return false;
        //         }
        //     }
        // }
        int row = (i/3)*3,col = (j/3)*3;

        for(int k=row;k<row+3;k++){
            for(int l=col;l<col+3;l++){
                if(board[k][l] == val+'0') return false;
            }
        }
        return true;
    }
    bool findAns(vector<vector<char>>& board){
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                if(board[i][j] == '.'){
                    for(int val=1;val<=9;val++){
                        if(isValid(i,j,val,board)){
                            board[i][j] = val+'0';
                            if(findAns(board)) return true;

                            board[i][j] = '.';
                        }
                    }

                    return false;
                }
            }
        }

        return true;
    }
public:
    void solveSudoku(vector<vector<char>>& board) {
        findAns(board);

    }
};  