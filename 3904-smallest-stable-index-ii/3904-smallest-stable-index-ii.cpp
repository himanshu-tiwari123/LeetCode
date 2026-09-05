class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n = nums.size();

        
        vector<int>prefMax(n) , suffMin(n);
        prefMax[0] = nums[0];
        suffMin[n-1] = nums[n-1];

        for(int i=0;i<n;i++){
            if(i>0) prefMax[i] = max(prefMax[i-1] ,nums[i]);
            if(n-i < n) suffMin[n-1-i] = min(suffMin[n-i],nums[n-1-i]);
        }


        for(int i=0;i<n;i++){
            int curr_val = prefMax[i] - suffMin[i];
            if(curr_val <= k){
                return i;
            }
        }



        return -1;
    }
};