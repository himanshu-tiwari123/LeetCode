class Solution {
public:
    string removeSubstring(string s, int k) {
        int n = s.size();
        vector<pair<char,int>>v;

        for(int i=0;i<n;i++){
            if(!v.empty() and v.back().first == s[i]){
                v.back().second++;
            }else{
                v.push_back({s[i],1});
            }

            while(v.size()>=2){
                int m = v.size();
                if(v[m-1].second>=k and v[m-1].first==')' and 
                   v[m-2].second>=k and v[m-2].first=='('  ){

                    v[m-1].second -=k;
                    v[m-2].second -=k;

                    if(v[m-1].second == 0) v.pop_back();

                    if(v.back().second == 0) v.pop_back();

                }else{
                    break;
                }
            }
        }

        string ans = "";

        for(auto &p:v){
            ans.append(p.second,p.first);
        }

        return ans;
    }
};