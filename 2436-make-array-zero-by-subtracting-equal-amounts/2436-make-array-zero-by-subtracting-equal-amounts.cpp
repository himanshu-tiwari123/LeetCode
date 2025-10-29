class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int n = nums.size();
        int min_element = INT_MAX;

        for(int i=0;i<n;i++){
            if(nums[i]>0 and nums[i] < min_element){
                min_element = nums[i];
            }
        }

        if(min_element == INT_MAX){
            return 0;
        }

        cout<<min_element<<" ";

        int cnt = 0;

        while(true){
            // if(min_element == 0) break;
            int val = INT_MAX;
            for(int i=0;i<n;i++){
                if(nums[i] > 0){
                    nums[i] -= min_element;

                    if(nums[i] > 0){
                        val = min (val,nums[i]);
                    }
                
                }
            }

            cnt++;

            min_element = val;

            if(val == INT_MAX) break;
        }

        return cnt;
    }
};