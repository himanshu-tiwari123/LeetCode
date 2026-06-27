class Solution {
    const int modulo = 1e9+7;
    using ll = long long;
public:
    int countHousePlacements(int n) {
        vector<int>dp(n+1,-1);

        dp[1] = 2;

        auto findAns =[&](auto &&self, int n)->int{
            if(n<=0){
                return 1;
            }
            if(n==1){
                return 2;
            }

            if(dp[n] != -1){
                return dp[n];
            }

            int not_place = self(self,n-1);

            int place = self(self, n-2);

            return dp[n] = (place + not_place)%modulo;

        };

        ll res = findAns(findAns,n);

        return (res*res)%modulo;
    }
};