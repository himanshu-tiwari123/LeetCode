class Solution {
public:
    vector<int> countRectangles(vector<vector<int>>& rectangles, vector<vector<int>>& points) {
        vector<vector<int>>x_vals(101);

        for(auto &it : rectangles){
            int x=it[0],y=it[1];
            for(int i=1;i<=y;i++){
                x_vals[i].push_back(x);
            }
        }

        for(int i=1;i<=100;i++){
            sort(x_vals[i].begin(),x_vals[i].end());
        }

        vector<int>res;

        for(auto &it : points){
            int x=it[0],y=it[1];
            auto lb = lower_bound(x_vals[y].begin(),x_vals[y].end(),x);
            int ans = (x_vals[y].end() - lb);

            res.push_back(ans);
        }

        return res;
    }
};