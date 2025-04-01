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
        dp.resize(n+1,-1);
        ll sum = findAns(0,questions);

        return sum;
    }
};