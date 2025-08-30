class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int n = board.size(),m = board[0].size();

        //check for all rows:
        for(int i=0;i<n;i++){
            int freq[10]={0};
            for(int j=0;j<m;j++){
               if(board[i][j]!='.'){
                    freq[board[i][j] - '0']++;
                    if(freq[board[i][j]-'0'] >= 2){
                        return false;
                    }
                }
            }
        }

        //check all cols:
        for(int j=0;j<m;j++){
            int freq[10]={0};
            for(int i=0;i<n;i++){
                if(board[i][j]!='.'){
                    freq[board[i][j]-'0']++;
                    if(freq[board[i][j]-'0'] >= 2){
                        return false;
                    }
                }
               
            }
        }

        //check all 3*3 submatrices:
        for(int i=0;i<8;i+=3){

            for(int j=0;j<8;j+=3){
                int freq[10] = {0};
                for(int k=i;k<(i+3);k++){
                    for(int l=j;l<(j+3);l++){
                        if(board[k][l]!='.'){
                            freq[board[k][l]-'0']++;
                            if(freq[board[k][l]-'0'] >= 2){
                                return false;
                            }
                        }
                    }
                }
            }
        }


        return true;
    }
};