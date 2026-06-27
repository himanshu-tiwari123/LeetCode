class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();

        vector<int>dp(n+1,-1);

        auto findAns = [&](auto &&self,int index)->int{
            if(index >= n){
                return 0;
            }
            if(dp[index] != -1){
                return dp[index];
            }
            int one_step = cost[index] + self(self,index+1);

            int two_steps = cost[index] + self(self,index+2);


            return dp[index] = min(one_step,two_steps);
        };


        return min(findAns(findAns,0), findAns(findAns,1));
    }
};