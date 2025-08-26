class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();

        int l=0,r=0;

        int min_length = INT_MAX;

        int curr_sum  =nums[0];

        while(r<n){
           

            if(curr_sum >= target){
                min_length =  min(min_length ,r-l+1);
                curr_sum -= nums[l];
                l++;
            }else{
                r++;
               if(r<n)curr_sum += nums[r];
            }
            
        }

        return (min_length!=INT_MAX ? min_length : 0);
    }
};