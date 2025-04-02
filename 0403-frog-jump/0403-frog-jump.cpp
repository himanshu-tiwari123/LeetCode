class Solution {
    set<int>st;
    vector<vector<int>>dp;
    bool findAns(int prev_jump,int curr_stone,vector<int>&stones){

        //Base Case:
        if(curr_stone == stones.back()){
            return true;
        }


        if(st.find(curr_stone)==st.end()){
            //this jump is not on stone:
            return false;
        }

        int curr_index = lower_bound(stones.begin(),stones.end(),curr_stone)-stones.begin();

        if(dp[prev_jump][curr_index]!=-1){
            return dp[prev_jump][curr_index];
        }

        bool ans = false;

        if(prev_jump>1){
             ans |= findAns(prev_jump-1,curr_stone+prev_jump-1,stones);
        }

        if(prev_jump > 0){
            ans |= findAns(prev_jump,curr_stone+prev_jump,stones);
        }

        ans |= findAns(prev_jump+1,curr_stone+prev_jump+1,stones);


        return dp[prev_jump][curr_index]=ans;
    }
public:
    bool canCross(vector<int>& stones) {
        int n = stones.size();
        for(auto &it:stones){
            st.insert(it);
        }
        dp.resize(n+1,vector<int>(n,-1));
        
        return findAns(1,1,stones);
    }
};