class Solution {
    vector<vector<int>>dp;

    int findLIS(int index,int prev_index,vector<int>&arr){
        //Base Case:
        if(index>=arr.size()){
            return 0;
        }
        if(dp[index][prev_index+1] !=-1){
            return dp[index][prev_index+1];
        }

        int not_take = 0+ findLIS(index+1,prev_index,arr);

        int take = 0;
        if(prev_index==-1 || arr[index] > arr[prev_index]){
            take = 1 + findLIS(index+1,index,arr);
        }


        return dp[index][prev_index+1] = max(take,not_take);
    }
    int findAns(vector<int>&arr){
        vector<int>lis;

        for(int i=0;i<arr.size();i++){
            if(lis.empty() || lis.back() < arr[i]){
                lis.push_back(arr[i]);
            }else{
                auto lb = lower_bound(lis.begin(),lis.end(),arr[i]);
                *lb = arr[i];
            }
        }

        return lis.size();
    }
public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        int n = envelopes.size();

        auto compare =[&](vector<int>a,vector<int>b){
            if(a[0] == b[0]) return a[1] > b[1];

            return a[0] < b[0];
        };

        sort(envelopes.begin(),envelopes.end(),compare);

        vector<int>temp;

        for(auto &it: envelopes){
            temp.push_back(it[1]);
        }

        // dp.resize(n+1,vector<int>(n+1,-1));

        // return findLIS(0,-1,temp);

        return findAns(temp);

        dp.resize(n+1,vector<int>(n+2,0));

        for(int index=n-1;index>=0;index--){

           for(int prev_index = n;prev_index>=0;prev_index--){

            int not_take = 0 + dp[index+1][prev_index];

            int take = 0;
            if(prev_index==0 || temp[index] > temp[prev_index-1]){
                take = 1 + dp[index+1][index+1];
            }


            dp[index][prev_index] = max(take,not_take);

           }
        }


        return dp[0][0];


    }
};