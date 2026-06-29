class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();

        if(n==1){
            return nums[0];
        }
        
        vector<int>dp1(n+1,-1),dp2(n+1,-1);

        auto findAns = [&](auto &self,int index,int end,vector<int>&dp)->int{
            //Base Case:
            if(index >= end){
                return 0;
            }

            if(dp[index] != -1){
                return dp[index];
            }


            int not_rob = self(self,index+1,end,dp);

            int rob = nums[index] + self(self,index+2,end,dp);


            return dp[index] = max(rob,not_rob);
        };


        return max(findAns(findAns,0,n-1,dp1) , findAns(findAns,1,n,dp2));

    }
};