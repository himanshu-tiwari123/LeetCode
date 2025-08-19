class Solution {
    #define ll long long
public:
    long long getDescentPeriods(vector<int>& prices) {
        int n = prices.size();

        if(n==1){
            return 1LL;
        }

        ll ans = 0;

        int j = 0;

        for(int i=0;i<n;i++){
            
            int len = 1;

            while((i+1)<n and prices[i+1]-prices[i]==-1){
                len++;
                i++;
            }

            ans += (ll)len*(len+1)/2;

        }

        return ans;


    }
};