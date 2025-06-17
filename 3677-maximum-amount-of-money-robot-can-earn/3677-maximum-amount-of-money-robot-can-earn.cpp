class Solution {
    
    int n,m;
    // vector<vector<int>>dp(n,vector<int>(m,-1));
    vector<vector<vector<int>>>dp;
   

    int findAns(int i,int j,int k,vector<vector<int>>& coins){
        //Base Case:
         if(i==n-1 and j==m-1){
            //you have reached end:
            if(coins[i][j]<0 and k>0){
                return 0; // we dont take this value:
            }else{
                return coins[i][j]; //add this value to ans:
            }

        }

        if(i>=n or j>=m){
            return -1e9;
        }

        if(dp[i][j][k]!=-1e9){
            return dp[i][j][k];
        }

        int best=-1e9;

        if(coins[i][j]<0 and k>0){
            // we try to skip them
           best =max(best,findAns(i,j+1,k-1,coins));
           best =max(best,findAns(i+1,j,k-1,coins));
        }
            best =max(best,coins[i][j] + findAns(i,j+1,k,coins));
            best =max(best,coins[i][j] + findAns(i+1,j,k,coins));
        
        return dp[i][j][k] =best;

    }
public:
    int maximumAmount(vector<vector<int>>& coins) {
       n=coins.size(),m=coins[0].size();
       dp.assign(n,vector<vector<int>>(m,vector<int>(3,-1e9)));
       return findAns(0,0,2,coins);
    }
};
       