class Solution {
    int dp[50][50][50][50];
public:
    int cherryPickup(vector<vector<int>>& grid) {
        int n = grid.size();

        if(n==1){
            return grid[0][0];
        }

       memset(dp,-1,sizeof(dp));
       
        auto findAns = [&](auto &self,int r1,int c1,int r2,int c2)->int{
            //Base Case:
            if(r1>=n or c1>=n or r2>=n or c2>=n or grid[r1][c1]==-1 or grid[r2][c2]==-1){
                return -1e9;
            }

            if(dp[r1][c1][r2][c2] != -1){
                return dp[r1][c1][r2][c2];
            }


            int curr_cherries = 0;

            if(r1==r2 and c1==c2){
                curr_cherries += grid[r1][c1];
            }else{
                curr_cherries += (grid[r1][c1] + grid[r2][c2]);
            }


            if((r1==n-1 and c1==n-1) or (r2==n-1 and c2==n-1)){
                return grid[n-1][n-1];
            }


            int mov1 = self(self,r1+1,c1,r2+1,c2);
            int mov2 = self(self,r1,c1+1,r2,c2+1);
            int mov3 = self(self,r1+1,c1,r2,c2+1);
            int mov4 = self(self,r1,c1+1,r2+1,c2);

            int max_future_cherries = max({mov1,mov2,mov3,mov4});

            return dp[r1][c1][r2][c2] = curr_cherries + max_future_cherries;



        };



        return findAns(findAns,0,0,0,0) < 0 ? 0 : findAns(findAns,0,0,0,0) ;

       
    }
};