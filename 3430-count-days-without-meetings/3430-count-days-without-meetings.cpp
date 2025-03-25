class Solution {
public:
    int countDays(int days, vector<vector<int>>& meetings) {
        // auto compare = [&](vector<int>a,vector<int>b){
        //     return a<b;
        // };
        int n=meetings.size();
        sort(meetings.begin(),meetings.end());

        int prevStart=0,prevEnd=0;

        int available = 0;

        for(int i=0;i<n;i++){
            int currStart=meetings[i][0],currEnd=meetings[i][1];
            if(currStart > prevEnd){
               available += currStart-prevEnd-1;
            }
            prevEnd = max(currEnd,prevEnd);
        }

        if(prevEnd < days){
            available += days-prevEnd;
        }

        // for(auto &it:meetings){
        //     cout<<it[0]<<" "<<it[1]<<"\n";
        // }


        return  available;

    }
};