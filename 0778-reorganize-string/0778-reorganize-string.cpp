class Solution {

    using P = pair<int,int>;
public:
    string reorganizeString(string s) {
        int n = s.size();
        unordered_map<char,int>mp;

        for(int i=0;i<s.size();i++){
            mp[s[i]]++;
        }

        priority_queue<P,vector<P>>pq;

        for(auto &it: mp){
            pq.push({it.second,it.first});
        }

        string ans = "";

        while(pq.size() > 1){
            auto [f1,c1] = pq.top();pq.pop();
            auto [f2,c2] = pq.top();pq.pop();
             
            ans += c1;
            ans += c2;

            f1--;f2--;

            if(f1 > 0) pq.push({f1,c1});
            if(f2 > 0) pq.push({f2,c2});

        }

        if(pq.size() == 1){
            auto [f,c] = pq.top();

            if(f == 1){
                ans += c;
            }else{
                return "";
            }
        }


        return ans;
    }
};