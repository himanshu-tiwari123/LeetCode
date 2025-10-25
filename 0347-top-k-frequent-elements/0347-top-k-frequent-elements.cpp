class Solution {
    using V = vector<int>;
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int  n = nums.size();

        unordered_map<int,int>mp;

        for(auto &it: nums){
            mp[it]++;
        }

        vector<V>bucket(n+1);

        for(auto &it: mp){
            int val = it.first;
            int freq = it.second;

            bucket[freq].push_back(val);
        }

        vector<int>ans;

        for(int i=n;i>=0;i--){
            if(k<=0) break;
            if(bucket[i].size() == 0) continue;
            for(int j=0;j<bucket[i].size() and k>0;j++){
                ans.push_back(bucket[i][j]);
                k--;
            }
        }

        return ans;




    }
};