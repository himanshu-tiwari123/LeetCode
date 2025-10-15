class Solution {
public:
    bool canJump(vector<int>& nums) {

        int n = nums.size();

        if(n>1 and nums[0] == 0)  return false;

        int max_jump = 0;

        for(int i=0;i<n;i++){
            if(i>max_jump){
                return false;
            }

            max_jump = max(max_jump,i+nums[i]);

            if(max_jump >= n-1){
                return true;
            }
        }

        return false;
        
    }
};