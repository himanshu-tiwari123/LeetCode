class Solution {
public:
    int countCompleteSubarrays(vector<int>& nums) {
        //Brute Force:

        int n = nums.size();

        unordered_set<int>ust;

        for(auto &it:nums){
            ust.insert(it);
        }

        int distinct = ust.size();

        int complete_subarrays = 0;

        for(int i=0;i<n;i++){
            unordered_set<int>st;
           for(int j=i;j<n;j++){
            st.insert(nums[j]);
                if(st.size() == distinct){
                    complete_subarrays++;
                }
           }
        }

        return complete_subarrays; 
    }
};