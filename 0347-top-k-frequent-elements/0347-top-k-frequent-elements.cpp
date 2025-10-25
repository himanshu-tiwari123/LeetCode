class Solution {
    #define P pair<int,int>;
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int>mp;

        for(auto &it: nums){
            mp[it]++;
        }

        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;

        for(auto &it: mp){
            int val = it.first;
            int freq = it.second;

            pq.push({freq,val});

            if(pq.size() > k){
                pq.pop();
            }
        }

        vector<int>ans;

        while(!pq.empty()){
           auto [f,v] = pq.top();

           ans.push_back(v);

           pq.pop();
        }

        return ans;


    }
};