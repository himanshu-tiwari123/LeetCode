class Solution {
    vector<vector<int>>grid;
    int val=0;
    void fill_grid(int row,int col,int size){
        //Base Case:
        if(size == 1){
            grid[row][col]=val++;
            return;
        }

        fill_grid(row,col+(size/2),(size/2));
        fill_grid(row+(size/2),col+(size/2),size/2);
        fill_grid(row+(size/2),col,size/2);
        fill_grid(row,col,size/2);
    }
public:
    vector<vector<int>> specialGrid(int N) {
        int n = 1<<N;
        grid.resize(n,vector<int>(n));
        fill_grid(0,0,n);
        return grid;

    }
};