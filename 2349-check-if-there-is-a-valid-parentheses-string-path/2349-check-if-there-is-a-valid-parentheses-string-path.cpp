class Solution {
    int n,m;
    
    int dp[101][101][200];

    bool findAns(int i,int j,int balance,vector<vector<char>>& grid){
        //Base Case:
        if(i>=n or j>=m){
            return false;
        }

        if(grid[i][j]=='(') balance++;
        else balance--;

        if(balance < 0){
            return false;
        }

        if(i==n-1 and j==m-1){
            return balance==0;
        }

        if(dp[i][j][balance] !=-1){
            return dp[i][j][balance];
        }

        bool right = findAns(i,j+1,balance,grid);

        bool down = findAns(i+1,j,balance,grid);


        return dp[i][j][balance] = right || down;
    }
public:
    bool hasValidPath(vector<vector<char>>& grid) {
        n=grid.size(),m = grid[0].size();
       
        memset(dp,-1,sizeof(dp));
        // string s = "";

        int balance = 0;
        
        return  findAns(0,0,balance,grid);
    
    
    }
};