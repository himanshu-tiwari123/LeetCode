class Solution {
    #define ll long long
    int subarraysAtmostK(vector<int>&nums,int k){
        int l=0,r=0;

        int n  = nums.size();
        unordered_map<int,int>mp;

        int subarrays = 0;

        while(r<n){
           mp[nums[r]]++;

           while(mp.size() > k){
                mp[nums[l]]--;

                if(mp[nums[l]] == 0){
                    mp.erase(nums[l]);
                }

                l++;
           }
            subarrays += (r-l+1);

            r++;
        }


        return subarrays;
    }
public:
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        int n = nums.size();
        //NOTE: count of subarrays with exact k distinct elements = 
        //         count of subarrays with atmost k distinct elements - 
        //         count of subarrays with atmost k-1 distinct elements!!!

       return subarraysAtmostK(nums,k) - subarraysAtmostK(nums,k-1);
    }
};