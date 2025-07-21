class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int n = nums.size();
        int low=0, high= n-1;

        while(low<=high){
            int mid = low + (high-low)/2;
            if(nums[mid] == target){
                return true;

            }
            //Skip duplicates:
            if(nums[mid]==nums[low] and nums[mid] == nums[high]){
                low++;
                high--;
            }else if(nums[low] <= nums[mid]){
                //left part is sorted:
                if(nums[low]<=target and target<=nums[mid]){
                    high = mid-1;
                }else{
                    low = mid+1;
                }
            }else{
                //right part is sorted:
                if(nums[mid]<=target and target<=nums[high]){
                    low = mid+1;
                }else{
                    high = mid-1;
                }
            }
        }

        return false;
    }
};