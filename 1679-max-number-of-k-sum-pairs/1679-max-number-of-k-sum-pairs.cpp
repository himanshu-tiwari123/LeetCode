class Solution {
    #define ll long long
public:
    int maxOperations(vector<int>& nums, int k) {
        int n = nums.size();
        
        unordered_map<int,int>mp;

        int cnt = 0;

        for(int i=0;i<n;i++){
            int req_sum = k - nums[i];

            if(mp.count(req_sum)){
                cnt++;
                mp[req_sum]--;

                if(mp[req_sum] == 0){
                    mp.erase(req_sum);
                }
            }else{
                mp[nums[i]]++;
            }
        }

       

        return cnt;

    }
};