class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size(),m = nums2.size();
        // vector<int>arr;
        int i=0,j=0;
        int index=0,val1=-1,val2=-1;
        int k = ((m+n)/2)-1;
        while(i<n and j<m){

            if(val1>=0 and val2>=0){
                break;
            }
            
            if(nums1[i] <= nums2[j]){
                if(index==k){
                    val1 = nums1[i];
                }
                if(index==k+1){
                    val2 = nums1[i];
                }
                
                i++;
            }else{
                if(index==k){
                    val1 = nums2[j];
                }
                if(index==k+1){
                    val2 = nums2[j];
                }
                
                j++;
            }
            index++;
        }

        while(i<n){
            if(index==k){
                val1 = nums1[i];
            }
            if(index==k+1){
                val2 = nums1[i];
            }
            index++;
            i++;
        }

        while(j<m){
            if(index==k){
                val1 = nums2[j];
            }
            if(index==k+1){
                val2 = nums2[j];
            }
            index++;
            j++;
        }

        double ans = 0.0;

        if((n+m)&1){
            //its odd:
            ans = val2;
        }else{
            ans = (val1 + val2)/2.0;
        }
        return  ans;

    }
};