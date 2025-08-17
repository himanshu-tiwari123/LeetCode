#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    long long maxProfit(vector<int>& prices, vector<int>& strategy, int k) {
        int n = (int)prices.size();
        long long original = 0;
        for (int i = 0; i < n; ++i) original += (long long)strategy[i] * prices[i];

        int half = k / 2;

        
        vector<long long> leftDelta(n), rightDelta(n);
        for (int i = 0; i < n; ++i) {
            leftDelta[i]  = - (long long)strategy[i] * (long long)prices[i];
            rightDelta[i] = (1LL - (long long)strategy[i]) * (long long)prices[i];   
        }

        // initial window s = 0
        long long leftSum = 0, rightSum = 0;
        for (int i = 0; i < half; ++i) leftSum += leftDelta[i];
        for (int i = half; i < k; ++i) rightSum += rightDelta[i];

        long long best = max(original, original + leftSum + rightSum);

        
        for (int s = 1; s + k - 1 < n; ++s) {

            leftSum  -= leftDelta[s - 1];
            leftSum  += leftDelta[s + half - 1];

            rightSum -= rightDelta[s + half - 1];
            rightSum += rightDelta[s + k - 1];

            best = max(best, original + leftSum + rightSum);
        }

        return best;
    }
};
