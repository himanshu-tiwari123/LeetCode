class Solution {
    int binarySearch(int target,int l,int h,vector<int>&arr){
        int ans = INT_MAX;
        while(l<=h){
           int mid = l + (h-l)/2;

            if(arr[mid] >= target){
              ans = min(ans,mid);
              h = mid-1;
            }else{
               l = mid+1;
           }
        }

        return ans;
    }
public:
    int findLengthOfShortestSubarray(vector<int>& arr) {
        int n = arr.size();
        int l=0,r=n-1;

        while((l+1)<n){
            if(arr[l] <= arr[l+1]) l++;
            else break;
        }

        while((r-1)>=0){
            if(arr[r] >= arr[r-1]) r--;
            else break;
        }

        if(l>=r) return 0;
        //if left subarray is sorted and right is not,we might want to eliminate the right half: so delete n-(left+1) else we might want to delete the left half ie,0 to right-1 ie.right:
        long long ans = min(n-(l+1),r);

        for(int i=0;i<=l;i++){
            //for each l we want to find the corresponding r such that arr[r] >= arr[l] and so the length of mid segment to be removed is r-l+1;
            long long j = binarySearch(arr[i],r,n-1,arr);

            ans = min(ans,j-(i+1));
        }


        return ans;
    }
};