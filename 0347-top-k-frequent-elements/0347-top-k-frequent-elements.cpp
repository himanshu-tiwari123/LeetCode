class Solution {
    using P = pair<int,int>;
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {

        //SOLUTION : USING O(N LOG K):
        int n = nums.size();
        // vector<int>ans;
        // unordered_map<int,int>mp;
        // priority_queue<P,vector<P>,greater<P>>pq;

        // for(int i=0;i<nums.size();i++){
        //    mp[nums[i]]++;
        // }

        // for(auto &it: mp){
           
        //     if(pq.size() >= k){
        //         int freq1 = pq.top().first;
        //         int freq2 = it.second;
        //         if(freq2 >  freq1){
        //             pq.pop();
        //             pq.push({it.second,it.first});
        //         }
        //     }else{
        //         pq.push({it.second, it.first});
        //     }

            
        // }

        // while(!pq.empty()){
        //     int val = pq.top().second;

        //     ans.push_back(val);

        //     pq.pop();
        // }


        // return ans;

        //SOLUTION 2 : USING BUCKET SORT:
        unordered_map<int,int>mp;

        for(auto &it: nums){
            mp[it]++;
        }

        vector<vector<int>>bucket(n+1);

        // bucket[i] -> all those elements having frequency of i

        vector<int>ans;

        for(auto &it: mp){
           bucket[it.second].push_back(it.first);
        }


        for(int i=bucket.size()-1; i>= 0 and ans.size() < k; i--){
            for(auto &it: bucket[i]){
               if(ans.size() > k) break;
               ans.push_back(it);
            }
        }

        return ans;
    }
};