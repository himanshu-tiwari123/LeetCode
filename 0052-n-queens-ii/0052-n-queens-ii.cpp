class Solution {
public:
    int ways_count = 0;

    unordered_set<int>cols;
    unordered_set<int>diagonals;
    unordered_set<int>antiDiagonals;


    void findAns(int row,vector<string>&grid){
        //Base Case:
        if(row>=grid.size()){
            ways_count++;
            return;
        }

        for(int col=0;col<grid.size();col++){

            if(cols.find(col)==cols.end() &&
               diagonals.find(col+row) == diagonals.end() &&
               antiDiagonals.find(row-col) == antiDiagonals.end()
            )  {
                //It means we can place the Queen here:
                cols.insert(col);
                diagonals.insert(row+col);
                antiDiagonals.insert(row-col);

                grid[row][col] = 'Q';

                findAns(row+1,grid);

                grid[row][col] = '.';

                cols.erase(col);
                diagonals.erase(row+col);
                antiDiagonals.erase(row-col);
                
            }
        }
    }
    int totalNQueens(int n) {
        vector<string>grid(n,string(n,'.'));
        findAns(0,grid);

        return ways_count;
    }
};