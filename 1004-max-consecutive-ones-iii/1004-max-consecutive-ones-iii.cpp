class Solution {

    bool isPossible(int mid,int high,vector<int>&arr,int k){
        if(arr[high]-( mid>0 ? arr[mid-1] :  0) <= k){
            return true;
        }

        return false;
    }
public:
    int longestOnes(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int>prefixSum(n,0);

        prefixSum[0] = (nums[0]==0);
        
        for(int i=1;i<n;i++){
            prefixSum[i] = (prefixSum[i-1] + (nums[i]==0));
        }

        int zero_count = prefixSum[n-1];

        if(zero_count <= k){
            return n;
        }


   
        //Now we can apply BS on this cause, its in ascending order :
        int max_consecutive_ones = 0;

        for(int i=0;i<n;i++){
            
                int high = i, low = 0;
                int index = i+1;

                while(low <= high){
                    int mid = low + (high-low)/2;

                    if(isPossible(mid,i,prefixSum,k)){
                        index = mid;
                        high = mid-1;
                    }else{
                        low = mid+1;
                    }
                    
                }

                max_consecutive_ones = max(max_consecutive_ones, i-index+1);
            
        }


        return max_consecutive_ones;
    }
};