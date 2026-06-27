class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int max_profit = 0;
        int buy = INT_MAX;

        for(int i=0;i<prices.size();i++){
            buy = min(buy, prices[i]);
            int curr_profit = prices[i] - buy;

            max_profit = max(max_profit,curr_profit);
        }

        return max_profit;
    }
};