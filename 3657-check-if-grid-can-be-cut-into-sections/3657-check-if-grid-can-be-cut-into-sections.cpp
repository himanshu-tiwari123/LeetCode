class Solution {
    vector<pair<int,int>>mergeKaro(vector<pair<int,int>>&intervals){
        vector<pair<int,int>>res;
        res.push_back({0,0});

        for(auto &it:intervals){
            int currStart = it.first,currEnd= it.second;
        
            int prevStart = res.back().first,prevEnd = res.back().second;
            if(prevEnd > currStart){
                //merge karna padega:
                res.pop_back();
                res.push_back({prevStart,max(currEnd,prevEnd)});

            }else{
                //merge nhi kar skte:
                res.push_back({currStart,currEnd});
            }
        }

        return res;
    }
public:
    bool checkValidCuts(int n, vector<vector<int>>& rectangles) {
        // int n = rectangles.size();
        vector<pair<int,int>>x,y;

        for(auto &it:rectangles){
            x.push_back({it[0],it[2]});
            y.push_back({it[1],it[3]});
        }

        sort(begin(x),end(x));
        sort(y.begin(),y.end());

        vector<pair<int,int>>merged_x = mergeKaro(x);
        vector<pair<int,int>>merged_y = mergeKaro(y);

        return (merged_x.size()>=4 || merged_y.size()>=4);
    }
};