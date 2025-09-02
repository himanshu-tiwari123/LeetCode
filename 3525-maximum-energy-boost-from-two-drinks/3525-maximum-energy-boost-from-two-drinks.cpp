class Solution {
public:
    long long maxEnergyBoost(vector<int>& energyDrinkA, vector<int>& energyDrinkB) {
        int n = energyDrinkA.size();
        if (n == 0) {
            return 0;
        }

        // dp[i][j] = max energy from hour i to n-1,
        // given that at hour i we are on drink j (0 or 1).
        // We use n+1 rows to handle the base case at i=n easily.
        vector<vector<long long>> dp(n + 1, vector<long long>(2, 0));

        // Iterate backwards from the second to last hour
        for (int i = n - 1; i >= 0; --i) {
            // Case 1: We are on Drink A (j=0) at hour i
            // Option A: Continue with A -> energyDrinkA[i] + dp[i+1][0]
            // Option B: Switch to B -> 0 + dp[i+1][1]
            dp[i][0] = max((long long)energyDrinkA[i] + dp[i+1][0], dp[i+1][1]);

            // Case 2: We are on Drink B (j=1) at hour i
            // Option A: Continue with B -> energyDrinkB[i] + dp[i+1][1]
            // Option B: Switch to A -> 0 + dp[i+1][0]
            dp[i][1] = max((long long)energyDrinkB[i] + dp[i+1][1], dp[i+1][0]);
        }

        // The final answer is the best we can do starting from hour 0,
        // either with drink A or drink B.
        return max(dp[0][0], dp[0][1]);
    }
};