class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int  n= nums.size();

        int candidate=0,cnt= 0;

        for(int i=0;i<n;i++){
            if(cnt == 0){
                candidate = nums[i];
            }
            if(nums[i]==candidate){
              cnt++;
            }else{
                cnt--;
            }
        }

        // cnt=0;

        // for(int i=0;i<n;i++){
        //     if(nums[i]== candidate){
        //         cnt++;
        //     }
        // }


        return candidate;
    }
};