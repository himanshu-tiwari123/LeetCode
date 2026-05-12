class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int zero_cnt = 0, ans = 0 , n = nums.size();
        int l = 0,r=0;

        while(r<n){

            if(nums[r] == 0){
                zero_cnt ++ ;
            }

            while(zero_cnt > k){
                if(nums[l] == 0){
                    zero_cnt--;
                }
                l++;
            }


            ans = max(ans, r-l+1);
            r++;

        }

        return ans;
    }
};