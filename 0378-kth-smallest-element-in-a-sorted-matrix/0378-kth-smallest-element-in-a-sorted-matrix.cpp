class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n = matrix.size(), m = matrix[0].size();
        int low=matrix[0][0],high = matrix[m-1][n-1];

        int ans = 0;

        while(low <= high){
            int mid = low + (high-low)/2;

            int cnt = 0;

            for(int i=0;i<n;i++){
                cnt += upper_bound(matrix[i].begin(),matrix[i].end(),mid)-matrix[i].begin();

            }

            if(cnt>=k){
                ans = mid;
                high = mid-1;
            }else{
                low = mid+1;
            }
        }

        return ans;
    }
};