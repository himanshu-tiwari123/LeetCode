class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int low= 1,high = nums.size()-2 , n = nums.size();
        //Resolving base Cases:

        if(n==1){
            return nums[0];
        }
        //
        if(nums[0]!=nums[1]){
            return nums[0];
        }

        if(nums[n-1]!=nums[n-2]){
            return nums[n-1];
        }

        //Here we will be using (even,odd) and (odd,even) concept:
        //If index is odd and to its left elemet same exists then we will
        //trim search space from left;
        //else if index is odd and its right same element exists then we 
        //will trim search space from right;

        while(low<=high){
            int mid = low + (high-low)/2;

            if(nums[mid]!=nums[mid-1] and nums[mid]!=nums[mid+1]){
                return nums[mid]; //This is our answer else:
            }
            else if(((mid%2)!=0 and nums[mid]==nums[mid-1]) ||
                    ((mid%2)==0 and  nums[mid]==nums[mid+1])){
                        //trim down left search spacd:
                        low = mid+1;
            }else{
                high = mid-1;
            }

            
        }

        return 0;
    }
};