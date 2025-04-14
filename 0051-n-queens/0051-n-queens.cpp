class Solution {
    
    vector<vector<string>>ans;

    bool isPossible(int row,int col,vector<string>&grid){
        //First check for column:
        for(int i=0;i<row;i++){
            if(grid[i][col] == 'Q'){
                return false;
            }
        }

        //Check for left-diagonal:
        int i=row,j=col;
        while(i>=0 && j>=0){
           if(grid[i][j] == 'Q'){
               return false;
           }
           i--;j--;
        }
        //Check for right-diagonal:
        i=row,j=col;
        while(i>=0 && j<grid.size()){
           if(grid[i][j] == 'Q'){
               return false;
           }
           i--;j++;
        }

        return true;
    }

    void findAns(int row,vector<string>&grid){
        //Base Case:
        if(row>=grid.size()){
            ans.push_back(grid);
            return;
        }

        for(int col=0;col<grid.size();col++){
            if(isPossible(row,col,grid)){
                grid[row][col] = 'Q';//It means queen has been placed ,now move to the next row:
                findAns(row+1,grid);

                grid[row][col] = '.'; //Backtrack to remove and check for other possiblities
            }
        }
    }
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<string>grid(n,string(n,'.'));
        findAns(0,grid);
        return ans;
    }
};