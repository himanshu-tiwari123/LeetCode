class Solution {
public:
    int maxSum(vector<int>& nums) {
        int sum1 = INT_MIN,sum2 = *max_element(nums.begin(),nums.end());

        unordered_set<int>st;
        int curr_sum = 0;

        for(int i=0;i<nums.size();i++){
            if(st.find(nums[i]) == st.end() and nums[i]>=0){
               curr_sum += nums[i];
               sum1 = max(sum1 , curr_sum);
            }
            st.insert(nums[i]);
        }

        return max(sum1,sum2);
    }
};