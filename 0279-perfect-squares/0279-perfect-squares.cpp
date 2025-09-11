class Solution {
    vector<vector<int>>dp;
    

    int findAns(int index,int target,vector<int>&coins){
        //Base Condition:
        if(index>=coins.size()){
            return INT_MAX;
        }

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

        dp.resize(coins.size(),vector<int>(n+1,-1));

        return findAns(0,n,coins);
    }
};