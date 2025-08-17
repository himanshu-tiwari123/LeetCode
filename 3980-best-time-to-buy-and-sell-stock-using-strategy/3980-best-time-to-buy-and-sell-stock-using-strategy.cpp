class Solution {
    #define ll long long
public:
    long long maxProfit(vector<int>& prices, vector<int>& strategy, int k) {
        int n = prices.size();
        vector<ll>leftDelta(n) , rightDelta(n);

        ll originalSum = 0;

        for(int i=0;i<n;i++){
            originalSum += (strategy[i] * prices[i]);
        }

        for(int i=0;i<n;i++){
            leftDelta[i] = (0-strategy[i]) * prices[i];
            rightDelta[i] = (1-strategy[i]) * prices[i];
        }

        ll leftSum = 0,rightSum =0;

        for(int i=0;i<(k/2);i++){
            leftSum += leftDelta[i];
        }

        for(int i=(k/2);i<(k);i++){
            rightSum += rightDelta[i];
        }
        

        ll maxSum = originalSum;

        maxSum = max(maxSum , originalSum + rightSum + leftSum);

        int l=1,r=k;

        while(r<n){
            leftSum -= leftDelta[l-1];
            leftSum += leftDelta[l+(k/2)-1];

            rightSum -= rightDelta[l+(k/2)-1];
            rightSum += rightDelta[r];

            l++;
            r++;

            maxSum = max(maxSum , originalSum + leftSum + rightSum);
        }

        return maxSum;
    }
};