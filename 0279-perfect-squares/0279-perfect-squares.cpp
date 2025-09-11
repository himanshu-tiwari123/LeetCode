class Solution {
    vector<vector<int>>dp;
    

    int findAns(int index,int target,vector<int>&coins){
        //Base Condition:
        // if(index>=coins.size()){
        //     return INT_MAX;
        // }

        if(index ==  coins.size()-1){
            if((target % coins[index]) == 0){
                return target/coins[index];
            }

            return INT_MAX;
        }


        if(dp[index][target]!=-1){
            return dp[index][target];
        }

        int not_take = findAns(index+1,target,coins);
        int take = 1e9;

        if(target >= coins[index]){
            take =1+findAns(index,target-coins[index],coins);
        }

        return dp[index][target] = min(take,not_take);
    }
public:
    int numSquares(int n) {
        //similar to coin change man:
        vector<int>coins;
        int i=1;
        while((i*i) <= n){
            coins.push_back(i*i);
            i++;
        }

        int m = coins.size();

        dp.resize(m+1,vector<int>(n+1,INT_MAX));

        // return findAns(0,n,coins);

        // Lets to tabulation approach:
        for(int target=0;target<=n;target++){
            if(target%coins[0] ==0){
                dp[0][target] = (target/coins[0]);
            }
        }

        for(int index=1;index<m;index++){
            for(int target=0;target<=n;target++){
              int not_take = dp[index-1][target];

              int take = 1e9;

              if(target-coins[index] >=0){
                take = 1 + dp[index][target-coins[index]];
              }

              dp[index][target] = min(take,not_take);

            }
        }

        return dp[m-1][n];
    }
};
