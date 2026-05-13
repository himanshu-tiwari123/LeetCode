class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n = nums.size();

        int last_index = -1;

        for(int i=0;i<n;i++){
            if(nums[i] != 0){

                nums[last_index + 1] = nums[i];

                last_index += 1;

            }
        }

        for(int i=last_index+1; i<n ; i++){
            nums[i] = 0;
        }

       
    }
};