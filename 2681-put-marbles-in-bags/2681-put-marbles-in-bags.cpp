class Solution {
    #define ll long long
public:
    long long putMarbles(vector<int>& weights, int k) {
        int n = weights.size();
        vector<ll>adjSums(n-1);

        for(int i=0;i<n-1;i++){
           adjSums[i]=weights[i]+weights[i+1];
        }
        // adjSums[n-1] = weights[0]+weights[n-1];

        sort(adjSums.begin(),adjSums.end());

        ll minSum =0,maxSum=0;

        int i=0,j=n-2;
        k--;

        while(k--){
            minSum += adjSums[i++];
            maxSum += adjSums[j--];
        }

        return maxSum-minSum;

        
    }
};