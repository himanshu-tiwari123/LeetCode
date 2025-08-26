class Solution {
public:
    int areaOfMaxDiagonal(vector<vector<int>>& dimensions) {
        int max_area = 0;

        double diagonal = 0.0;

        vector<pair<double,int>>v;

        for(auto &it: dimensions){
            int a=it[0],b=it[1];

            double curr_diagonal = (double)sqrt((a*a) + (b*b));
            
            int area = a*b;

            v.push_back({curr_diagonal,area});
            
        }

        auto compare = [&](pair<double,int>a,pair<double,int>b){
            if(a.first == b.first){
                return a.second > b.second;
            }

            return a.first > b.first;
        };

        sort(v.begin(),v.end(),compare);

        return v[0].second;
    }
};