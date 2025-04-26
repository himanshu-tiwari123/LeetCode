class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int ans = 0;
        int n = nums.size();

        unordered_map<int,int>mp;
        mp[0]=1;

        int prefixSum = 0;

        for(int i=0;i<n;i++){
            prefixSum += nums[i];

            int val = prefixSum%k;

            if(val < 0 ? mp.count(val+k) : mp.count(val)){
                ans += (val< 0 ? mp[val+k] : mp[val]);
            }

            val<0 ? mp[val+k]++ : mp[val]++;

        }

        return ans;
    }
};