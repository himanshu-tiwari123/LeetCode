class Solution {
public:
    vector<int> minCosts(vector<int>& cost) {
        int  n = cost.size();
        vector<int>minCost(n,cost[0]);

        for(int i=1;i<n;i++){
            minCost[i] = min(cost[i],minCost[i-1]);
        }

        return minCost;
    }
};