class Solution {
public:
    vector<int> partitionLabels(string s) {
        ios_base::sync_with_stdio(false);
        cin.tie(0);
        cout.tie(0);
        
        vector<vector<int>>v(26,vector<int>(2,0));

        for(int i=0;i<s.size();i++){
            int index=s[i]-'a';
            if(v[index][0]==0){
                v[index][0]=(i+1);
                v[index][1]=(i+1);
            }else{
                v[index][1] = max(v[index][0],i+1);
            }
        }

        sort(v.begin(),v.end());

        // for(int i=0;i<26;i++){
        //     cout<<v[i][0]<<" "<<v[i][1]<<"\n";
        // }

        vector<pair<int,int>>merged;
        
        merged.push_back({0,0});

        for(int i=0;i<v.size();i++){
            int prevStart= merged.back().first;
            int prevEnd = merged.back().second;
            int currBegin = v[i][0],currEnd = v[i][1];

            if(prevEnd >= currBegin){
                merged.pop_back();
                merged.push_back({prevStart,max(prevEnd,currEnd)});
            }else{
                merged.push_back({currBegin,currEnd});
            }
        }

        vector<int>res;

        for(int i=1;i<merged.size();i++){
            res.push_back(merged[i].second - merged[i].first + 1);
        }
        


        return res;
    }
};