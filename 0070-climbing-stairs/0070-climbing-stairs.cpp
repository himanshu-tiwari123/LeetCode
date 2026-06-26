class Solution {
public:
    int climbStairs(int n) {

        vector<int>dp;

        dp.assign(n+1,-1);

        auto findAns = [&](auto &&self,int n)->int{
            if(n< 0) return 0;
            if(n==0 or n==1) return 1;

            if(dp[n] != -1){
                return dp[n];
            }

            int one_step = self(self, n-1);
            int two_steps = self (self, n-2);

            return dp[n] =  one_step + two_steps;

        };
        return findAns(findAns,n);
    }
};