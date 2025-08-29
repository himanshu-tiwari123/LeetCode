class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int n = nums.size();

        vector<int>prefixSum(n+2);
        prefixSum[0] =0,prefixSum[n+1] = 0;

        prefixSum[1] = nums[0];

        int total_sum = accumulate(nums.begin(),nums.end(),0);

        for(int i=2;i<=n;i++){
           prefixSum[i] = prefixSum[i-1] + nums[i-1];
        }
        int index = -1;
        for(int i=1;i<=n;i++){
            int lSum = prefixSum[i-1];
            int rSum = total_sum - prefixSum[i];

            if(lSum == rSum){
               index = i-1;
               break;
            }
        }

        return index;

        


        return index;
    }
};