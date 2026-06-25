class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n = intervals.size();

        vector<vector<int>>ans;

        auto compare =[&](vector<int>&a,vector<int>&b){
            if(a[0] == b[0]){
                return a[1]<b[1];
            }

            return a[0] < b[0];
        };

        sort(intervals.begin(),intervals.end(),compare);

        int prev =-1,i=0;

        while(i<n){
            if(intervals[i][0] > prev){
                ans.push_back(intervals[i]);
                prev = intervals[i][1];
            }else{
                vector<int>&temp = ans.back();
                while(i<n and prev >= intervals[i][0]){
                    temp[1] = max(temp[1],intervals[i][1]);
                    prev = max(prev,intervals[i][1]);
                    i++;
                }
                i--;
                // ans.pop_back();
                // ans.push_back(temp);
            }

            i++;


        }


        return ans;
    }
};