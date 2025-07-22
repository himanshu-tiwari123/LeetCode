class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();

        if(nums[0] <= nums[n-1]){
            //it means the numsay is already sorted:
            return nums[0];
        }

        int low = 0,high = n-1;

        while(low < high){
            int mid = low + (high-low)/2;

            if(nums[mid] > nums[high]){
                //left part is sorted:
                low = mid+1;
            }else{
                high = mid;
            }
        }

        return nums[low];
    }
};