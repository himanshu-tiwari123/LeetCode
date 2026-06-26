class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n= intervals.size();

        // auto compare = [&](vector<int>&a, vector<int>&b){
        //    return a[0] < b[0];
        // };

        sort(begin(intervals), end(intervals));

        vector<vector<int>>ans;

        int prev_interval= -1;

        for(auto &it: intervals){
            int start = it[0] , end = it[1];

            if(start > prev_interval){
                ans.push_back({start,end});
            }else{
                ans.back()[1] = max(prev_interval,end);

            }

            prev_interval = max(prev_interval,end);
        }


        return ans;


    }
};