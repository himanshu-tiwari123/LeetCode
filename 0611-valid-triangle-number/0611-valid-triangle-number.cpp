class Solution {
    int binarySearch(int val,int low,int high,vector<int>&arr){
        int index = -1;

        while(low<=high){
            int mid = (low + (high-low)/2);
            if(arr[mid] < val){
                index = mid;
                low = mid+1;
            }else{
                high = mid-1;
            }
        }

        return index;
    }
public:
    int triangleNumber(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(),nums.end());

        int cnt = 0;

        //a +b > c so we do a > c-b;

        for(int i=0;i<=(n-3);i++){
            int a = nums[i];
            for(int j=i+1;j<=(n-2);j++){
                int b = nums[j];
                int res= binarySearch(a+b,j+1,n-1,nums)-j;
                // cout<<res<<" ";
                cnt += max(res,0);
            }
        }

        return cnt;
    }
};