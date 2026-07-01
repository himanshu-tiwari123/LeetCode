class Solution {
    using P = pair<int,int>;
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int>ans;
        unordered_map<int,int>mp;
        priority_queue<P,vector<P>,greater<P>>pq;

        for(int i=0;i<nums.size();i++){
           mp[nums[i]]++;
        }


        for(auto &it: mp){
           
            // cout<<it.first<<" "<<it.second<<"\n";
            if(pq.size() >= k){
                int freq1 = pq.top().first;
                int freq2 = it.second;
                if(freq2 >  freq1){
                    pq.pop();
                    pq.push({it.second,it.first});
                }
            }else{
                pq.push({it.second, it.first});
            }

            
        }

        while(!pq.empty()){
            int val = pq.top().second;

            ans.push_back(val);

            pq.pop();
        }


        return ans;
    }
};