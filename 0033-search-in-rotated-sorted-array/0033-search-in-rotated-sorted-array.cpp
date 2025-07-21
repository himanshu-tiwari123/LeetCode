class Solution {
public:
    int search(vector<int>& nums, int target) {
        //so to search in a rotated sorted array we will keep track of arr[mid] and arr[high]
        //if(arr[mid] > arr[high])=>that part from mid to high is not sorted ,so pivot will be      
        // here and therefore we do low = mid+1 else we do high = mid-1.As soon as arr[mid]==target we 
        // return  it:

        int n = nums.size();

        int low = 0,high = n-1;

        while(low<=high){
            int mid = low + (high-low)/2;

            if(nums[mid] == target){
                return mid;
            }

            //Left part of array is sorted:
            if(nums[mid] > nums[high]){
                //check if targer is present here:
                if(nums[low] <= target and target<=nums[mid]){
                    high  = mid-1;
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

        return -1;
        
    }
};