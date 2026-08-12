class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int n = nums.size();

        unordered_map<int,int>mp;

        int l=0,r=0;

        int max_len = 0;

        while(r<n){
            mp[nums[r]]++;

            while(mp[nums[r]] > k){
                mp[nums[l]]--;
                // if(mp[nums[l]] == 0){
                //     mp.erase(mp.find(nums[l]));
                // }

               l++;
            }

            max_len = max(max_len, r-l+1);
            r++;
        }

        return max_len;
    }
};