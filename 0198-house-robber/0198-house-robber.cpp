class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        // vector<int>dp(n+1,-1);

        // auto findAns =[&](auto &self, int index)->int{
        //     //Base Case:
        //     if(index >= n){
        //         return 0;
        //     }

        //     if(dp[index] != -1){
        //         return dp[index];
        //     }

        //     int not_rob = self(self,index+1);

        //     int rob = nums[index] + self(self,index+2);


        //     return dp[index] = max(rob, not_rob); 
        // };

        vector<int>dp(n+2,0);


        for(int i=n-1;i>=0;i--){
            dp[i]= max(dp[i+1] , nums[i] + dp[i+2]);
        }


        return dp[0];




        // return findAns(findAns,0);
    }
};