class Solution {
public:
    vector<vector<int>> generate(int n) {
        vector<vector<int>>res;
        vector<vector<int>>dp(n+1,vector<int>(n+1,0));

        for(int i=0;i<=n;i++){
            dp[i][0]=1;
        }


        for(int i=0;i<n;i++){
           vector<int>ans;
           ans.push_back(1);
            for(int j=1;j<=i;j++){
               dp[i][j] = dp[i-1][j-1]+dp[i-1][j];
               ans.push_back(dp[i][j]);
            }

            res.push_back(ans);
        }

        return res;


    }
};