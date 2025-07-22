class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size(),m = nums2.size();
        vector<int>arr;
        int i=0,j=0;
        while(i<n and j<m){
            if(nums1[i] <= nums2[j]){
                arr.push_back(nums1[i]);
                i++;
            }else{
                arr.push_back(nums2[j]);
                j++;
            }
        }

        while(i<n){
            arr.push_back(nums1[i]);
            i++;
        }

        while(j<m){
            arr.push_back(nums2[j]);
            j++;
        }

        int len = arr.size();

        double ans = 0.0;

        if(len&1){
            //length is odd:
            ans =(double)arr[len/2];
        }else{
            ans = (arr[(len/2)]+arr[(len/2)-1])/2.0;
        }

        return ans;

    }
};