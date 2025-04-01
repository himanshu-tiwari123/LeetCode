class Solution {
    using ll = long long;
    vector<ll>dp;
    ll findAns(int index,vector<vector<int>>& questions){
        //Base Case:
        if(index>=questions.size()){
            return 0;
        }

        if(dp[index]!=-1){
            return dp[index];
        }

        ll not_take = findAns(index+1,questions);

        ll take = questions[index][0]+findAns(index+questions[index][1]+1,questions);

        return dp[index]=max(take,not_take);
    }
public:
    long long mostPoints(vector<vector<int>>& questions) {
        int n = questions.size();
        dp.resize(1e6,0);
        // ll sum = findAns(0,questions);

        for(int i=n-1;i>=0;i--){
            dp[i] = max(dp[i+1],questions[i][0]+dp[i+questions[i][1]+1]); 
        }

        return dp[0];


        // return sum;
    }
};