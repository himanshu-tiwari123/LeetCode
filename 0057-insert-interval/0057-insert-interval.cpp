class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int n = intervals.size();

        vector<vector<int>>ans;

        intervals.push_back(newInterval);

        sort(intervals.begin(), intervals.end());

        int prev_interval = -1;

        for(auto &it: intervals){
           int start = it[0] , end = it[1];

            if(start > prev_interval){
              ans.push_back({start,end});
            }else{
                ans.back()[1] = max(prev_interval,end);
            }


            prev_interval = max(prev_interval, end);
        }

        return ans;
    }
};