class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n= nums.size();
        //First find the break-point:

        int ind=-1;
        for(int i=n-2;i>=0;i--){
            if(nums[i] < nums[i+1]){
                ind = i;
                break;
            }
        }

        if(ind == -1){
            reverse(nums.begin(),nums.end());
        }else{
            //Swap this element at index ind with element on right-half which is next-greater element:
            for(int i=n-1;i>ind;i--){
                if(nums[i] > nums[ind]){
                    swap(nums[i],nums[ind]);
                    break;
                }
            }

            reverse(nums.begin()+ind+1,nums.end());
        }

    }
};