class Solution {
    bool isPossible(long long mid,vector<int>&nums){

        vector<long long>temp(nums.begin(),nums.end());
        
        int n = nums.size();

        for(int i=0;i<n-1;i++){

            if(temp[i] > mid){
              return false;
            }

            long long buffer = mid - temp[i];

            temp[i+1] -= buffer; 

        }

        return temp[n-1]<=mid;
    }
public:
    int minimizeArrayValue(vector<int>& nums) {
        int  n = nums.size();

        int low = 1;

        int high = *max_element(nums.begin(),nums.end());

        int min_value = high;

        while(low<=high){
            long long mid = low + (high-low)/2;
            
            
            if(isPossible(mid,nums)){
                min_value = mid;

                high = mid-1;

            }else{
                low = mid+1;
            }
        }

        return min_value;
    }
};