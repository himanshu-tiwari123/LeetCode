class Solution {
    using ll = long long;
    unordered_map<ll,int>dp;
    public:
    int findAns(ll n){
        if(n==1) return 0;

        if(dp.find(n) != dp.end()){
            return dp[n];
        }

        int min_ops1 = 0, min_ops2 = 0, min_ops3 = 0;

        if(n%2 == 0){
            min_ops1 = 1 + findAns(n/2);
        }else{
            min_ops2 = 1 + findAns(n-1);

            min_ops3 = 1 + findAns(n+1);
        }


        return dp[n] = min(min_ops1 + min_ops2 , min_ops1 + min_ops3);
    }
public:
    int integerReplacement(int n) {

        return findAns(n);
        
    }
};