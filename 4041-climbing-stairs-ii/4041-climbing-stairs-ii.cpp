#define ll long long

class Solution {
    private:
    vector<ll>dp;
    private:
    ll findAns(int index,vector<int>&costs){
       //Base Case:
       if(index>=costs.size()-1) return 0;


       if(dp[index]!=-1){
        return dp[index];
       }


       ll ans = 1e9;

        for(int j=index+1;j<=index+3 && j<costs.size();j++){
          ll curr_ans = (ll)(costs[j] + ((j-index) * (j-index))) + findAns(j,costs); 

          ans  = min(ans,curr_ans);
        }


        return dp[index] = ans;
    }

public:
    int climbStairs(int n, vector<int>& costs) {
        costs.insert(costs.begin(),0);

        dp.resize(n+1,-1);

        return findAns(0,costs);
    }
};