class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int>dp(n+1,-1);

        auto findAns =[&](auto &self, int index)->int{
            //Base Case:
            if(index >= n){
                return 0;
            }

            if(dp[index] != -1){
                return dp[index];
            }

            int not_rob = self(self,index+1);

            int rob = nums[index] + self(self,index+2);


            return dp[index] = max(rob, not_rob); 
        };


        return findAns(findAns,0);
    }
};