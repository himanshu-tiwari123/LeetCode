class Solution {
    using P = pair<int,char>;
public:
    string frequencySort(string s) {
        int n = s.size();

        priority_queue<P,vector<P>>pq;

        unordered_map<char,int>mp;

        for(int i=0;i<n;i++){
            mp[s[i]]++;
        }

        for(auto &it: mp){
            int ch = it.first;
            int freq = it.second;

            pq.push({freq,ch});
        }

        string ans = "";

        while(!pq.empty()){
            auto [f,ch] = pq.top();
            pq.pop();

            for(int i=0;i<f;i++){
                ans += ch;
            }
        }

        return ans;
    }
};