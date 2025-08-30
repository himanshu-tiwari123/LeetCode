class Solution {
    const int modulo = 1e9+7;
    int dp[505][505][3];
    // int visited[505][505][2];

    int findAns(int i,int j,int dir,vector<vector<int>>& grid){
        int n  = grid.size() , m = grid[0].size();
        //Base Case:
        if(i<0 or i>=n or j<0 or j>=m) return 0;

        if(i==n-1 and j== m-1) return 1;

        if(dp[i][j][dir] != -1){
            return dp[i][j][dir];
        }

        

        if(grid[i][j] == 1){
            if(dir == 0){
                return findAns(i+1,j,1,grid);
            }else{
                return findAns(i,j+1,0,grid);
            }
        }

        int right = findAns(i,j+1,0,grid);

        int down = findAns(i+1,j,1,grid);



        return dp[i][j][dir] = (right + down )%modulo;
    }
public:
    int uniquePaths(vector<vector<int>>& grid) {
        int n  = grid.size() , m = grid[0].size();
        
        memset(dp,-1,sizeof(dp));

        //0->right,1->down;

        int r = findAns(0,1,0,grid);

        int d = findAns(1,0,1,grid);

        return (r+d)%modulo;

    }
};