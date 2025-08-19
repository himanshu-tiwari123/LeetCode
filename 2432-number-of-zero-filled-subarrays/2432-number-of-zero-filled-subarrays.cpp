class Solution {
    #define ll long long
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        int n = nums.size();

        ll ans = 0;

        for(int i=0;i<n;i++){
            if(nums[i]==0){
                int l = 0;

                while(i<n and nums[i]==0){
                    l++;
                    i++;
                }

                ans += (ll)l*(l+1)/2;
            }
        }

        return ans;
    }
};