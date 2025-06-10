class Solution {
    #define ll long long
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        ll subarrays = 0;

        int n =nums.size();

        //no of subarrays = n*(n+1)/2;

        for(int i=0;i<n;i++){
            ll curr_length = 0; 
            while(i<n and nums[i]==0){
               curr_length++;
               i++;
            }

            subarrays += (curr_length * (curr_length+1))/2;
        }

        return subarrays;
    }
};