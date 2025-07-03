class Solution {
    vector<int>dp;

    int getIndex(int val,int low,int high,vector<vector<int>>&v){
        int index=-1;
       while(low<=high){
            int mid = low+(high-low)/2;

            if(v[mid][0] >= val){
               index = mid;
               high = mid-1;
            }else{
                low = mid+1;
            }
       }

       return index;

    }
    int findAns(int index, vector<vector<int>>&v){
        //Base Case:
        if(index>=v.size()){
            return 0;
        }

        if(dp[index]!=-1){
            return dp[index];
        }

        int not_take = findAns(index+1,v);

        int next_index = getIndex(v[index][1],index+1,v.size()-1,v);

        int take = v[index][2] + findAns(next_index,v);

        return dp[index]=max(take,not_take);
    }
public:
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        int n = startTime.size();
        //first we store all them in a single vector:
        vector<vector<int>>v(n,vector<int>(3));

        dp.resize(n,-1);

        for(int i=0;i<n;i++){
            v[i][0] = startTime[i];
            v[i][1] = endTime[i];
            v[i][2] = profit[i];
        }

        auto compare = [&](vector<int>a,vector<int>b){
            return a[0] < b[0];//sort based on start Time:
        };

        sort(v.begin(),v.end(),compare);

        //Now we can do take - not_take operations on intervals:

        return findAns(0,v);
    }
};