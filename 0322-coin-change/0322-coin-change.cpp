class Solution {
    private:
    int minCoins(int index , int amount , vector<int>&coins,vector<vector<int>>&dp){
        //Base Case:
        if(index == 0){
            if((amount%coins[0]) == 0){
                return (amount/coins[0]);
            }
            else{
                return 1e9;
            }
        }
        if(dp[index][amount]!=-1)  return dp[index][amount];

        int not_pick = minCoins(index-1 , amount,  coins,dp);

        int pick = 1e9;

        if(amount - coins[index]>=0){
            pick = 1 + minCoins(index , amount-coins[index] , coins,dp);
        }

        return dp[index][amount] =  min(pick , not_pick);
    }
public:
    int coinChange(vector<int>& coins, int amount) {
        //  pick or not pick
        int n= coins.size();

        vector<vector<int>>dp(n,vector<int>(amount+1,-1));

        int req_coins = minCoins(n-1 , amount , coins ,dp) ;

        return req_coins == 1e9 ? -1 : req_coins;
    }
};