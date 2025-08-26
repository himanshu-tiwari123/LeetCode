class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int n = nums.size();

        int curr_sum = 0;

        int max_sum1 = INT_MIN,max_sum2 = INT_MIN;

        for(int i=0;i<n;i++){
            curr_sum += nums[i];

            if(curr_sum >=0){
                max_sum1 = max(max_sum1,curr_sum);
            }else{
                curr_sum = 0;
            }
        }

        for(int i=0;i<n;i++){
            nums[i] *=-1;
        }

        curr_sum = 0;

        for(int i=0;i<n;i++){
            curr_sum += nums[i];

            if(curr_sum >=0){
                max_sum2 = max(max_sum2,curr_sum);
            }else{
                curr_sum = 0;
            }
        }

        return max(max_sum1,max_sum2);
    }
};