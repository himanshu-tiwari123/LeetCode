class Solution {
public:
    int minimumAddedCoins(vector<int>& coins, int target) {
        int curr_max = 0,add= 0;

        sort(coins.begin(),coins.end());

        int i=0;

        while(curr_max < target){
            if(i<coins.size() and coins[i] <= curr_max+1){
                curr_max += coins[i];
                i++;
            }else{
                curr_max = (2*curr_max)+1;
                add++;
            }
        }

        return add;
    }
};