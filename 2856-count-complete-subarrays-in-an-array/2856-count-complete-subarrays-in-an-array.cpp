class Solution {
public:
    int countCompleteSubarrays(vector<int>& nums) {
       int n = nums.size();

        unordered_set<int>ust;

        for(auto &it:nums){
            ust.insert(it);
        }

        int distinct = ust.size();

        int left = 0,right=0;

        unordered_map<int,int>mp;

        int complete_subarrays = 0;

        while(left<n){
            if(left > 0){
                mp[nums[left-1]]--;
                if(mp[nums[left-1]] == 0){
                    mp.erase(nums[left-1]);
                }
            }
            while(right<n and mp.size()<distinct){
                mp[nums[right]]++;
                right++;
            }
            if(mp.size() == distinct){
                complete_subarrays += (n-right+1);
                cout<<right<<" "<<complete_subarrays<<"\n";
            }

            left++;
        }

        
        return complete_subarrays;
        
    }
};