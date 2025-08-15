class Solution {
    const int M = 1e9+7;

    long long dp[5][4][5001];

    bool isValid(int i,int j,vector<vector<int>>&grid){
        int  n=grid.size(),m=grid[0].size();

        return ((i>=0 and i<n) and (j>=0 and j<m) and (grid[i][j]>=0));
    }

    int findAns(int i,int j,int cnt,int limit,vector<vector<int>>&grid){
        if(cnt>limit || (!isValid(i,j,grid))){
            return 0;
        }
        if(cnt == limit){
            return 1;
        }

        if(dp[i][j][cnt]!=-1){
            return dp[i][j][cnt];
        }


        int j1 = findAns(i-2,j-1,cnt+1,limit,grid);
        int j2 = findAns(i+2,j-1,cnt+1,limit,grid);
        int j3 = findAns(i-2,j+1,cnt+1,limit,grid);
        int j4 = findAns(i+2,j+1,cnt+1,limit,grid);
        int j5 = findAns(i-1,j-2,cnt+1,limit,grid);
        int j6 = findAns(i+1,j-2,cnt+1,limit,grid);
        int j7 = findAns(i-1,j+2,cnt+1,limit,grid);
        int j8 = findAns(i+1,j+2,cnt+1,limit,grid);


        return dp[i][j][cnt]=((long long)(j1)+(j2)+(j3)+(j4)+(j5)+(j6)+(j7)+(j8))%M;
    }
    
public:
    int knightDialer(int n) {

        vector<vector<int>>grid(4,vector<int>(3));

        for(int i=0;i<4;i++){
            for(int j=0;j<3;j++){
                if(i==0)  {grid[i][j] = (i+j+1);}
                else  {grid[i][j] = grid[i-1][j] + 3;}
            }
        }
    

        grid[3][0]=-1,grid[3][1]=0,grid[3][2]=-1;


        int ans  = 0;
        
        for(int i=0;i<4;i++){
            for(int j=0;j<3;j++){
                if(grid[i][j]>=0){
                    memset(dp,-1,sizeof(dp));
                   int cnt = 0;
                   ans = (ans + findAns(i,j,cnt,n-1,grid))%M;
                }
                
            }
        }

        return ans;
    }
};