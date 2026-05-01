class Solution {
    int dp[201][201][401];
    int n, m;


    int findAns(int i,int j,int k,vector<vector<int>>& grid){

        //base Case:
        if(i>=n or j>=m ){
            return -1e9;
        }
        
        int val = grid[i][j];

        if(val == 2){
            val = 1;
        }

        if(i==n-1 and j==m-1){
            if(k-val >=0 ){
                return grid[i][j];
            }else{
                return -1e9;
            }
        }

        if(dp[i][j][k] != -1){
            return dp[i][j][k];
        }

        int right = -1e9, down = -1e9;


        if(k-val >= 0){
            right = grid[i][j] + findAns(i+1, j, k-val,grid);
             
            down = grid[i][j] + findAns(i,j+1,k-val,grid);
        }

        return dp[i][j][k] = max(right, down);
        
    }
public:
    int maxPathScore(vector<vector<int>>& grid, int k) {
        n = grid.size(); m = grid[0].size();
         
        memset(dp,-1, sizeof(dp));

        if(k>400){
            k=400;
        }

        int ans = findAns(0,0,k,grid);

        return (ans < 0 ? -1 : ans);

          
    }
};