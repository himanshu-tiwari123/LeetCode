class Solution {
    vector<vector<int>>dp;
    int findAns(int index,int target,vector<int>&coins){
        //Base Case:
        if(target == 0){
            return 1;
        }
        if(target<0){
            return 0;
        }
        if(index==coins.size()-1){
            if((target%coins[index]) == 0){
                return 1;
            }else{
                return 0;
            }
        }
        if(dp[index][target] !=-1){
            return dp[index][target];
        }
        int not_take = findAns(index+1,target,coins);

        int take = 0;

        if(target-coins[index] >=0){
            take = findAns(index,target-coins[index],coins);
        }

        return dp[index][target]=take + not_take;
    }
public:
    vector<int> findCoins(vector<int>& numWays) {
        int n = numWays.size();

        vector<int>coins;

        
        for(int amount=1;amount<=n;amount++){
            
            // if(coins.size()==0 and  numWays[amount-1] == 1){
                
            //     coins.push_back(amount);
            // }
            // if(coins.size() == 0){
            //     continue;
            // }
           
            dp.assign(coins.size()+1,vector<int>(amount+1,-1));

            int curr_ways =(coins.size()>0 ? findAns(0,amount,coins) : 0);
                
            if(curr_ways == numWays[amount-1]) {
               continue;
            }else if(curr_ways+1 == numWays[amount-1]){
                coins.push_back(amount);
            }else{
                return {};
            }
            
        }


        return coins;


    }
};