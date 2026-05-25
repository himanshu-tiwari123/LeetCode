class Solution {
    using ll = long long;
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        
        int l=0,r=0;
        ll curr_sum = 0, max_sum = LLONG_MIN;

        unordered_map<int,int>mp;

        while(r<n){
            curr_sum += nums[r];
            mp[nums[r]]++;

            if(r-l+1==k){

                if(mp.size() == k){
                    // cout<<"Ho gaya\n";
                    max_sum = max(max_sum, curr_sum); 
                }

                curr_sum -= nums[l];
                mp[nums[l]]--;

                if(mp[nums[l]] == 0){
                    mp.erase(mp.find(nums[l]));
                }
                l++;

                
            
            }

            r++;
 
        }

        return max_sum == LLONG_MIN ? 0:max_sum;

    }
};