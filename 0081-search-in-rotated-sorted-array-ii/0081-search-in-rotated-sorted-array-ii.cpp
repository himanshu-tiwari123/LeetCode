class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int l=0,r=nums.size()-1;

        while(l<=r){
            int mid = l+(r-l)/2;

            if(nums[mid] == target){
                return true;
            }

            if(nums[mid]== nums[r] and nums[mid]==nums[l]){
                l++;
                r--;
                continue;
            }

            if(nums[mid] <= nums[r]){
                //right half is sorted:
                if(nums[mid]<=target and target<=nums[r]){
                    l = mid+1;
                }else{
                    r = mid-1;
                } 
            }else{
                //left half is sorted:
                if(nums[l]<=target and target<=nums[mid]){
                    r = mid-1;
                }else{
                    l = mid+1;
                }
            }
        }

        return false;
      
    }
};