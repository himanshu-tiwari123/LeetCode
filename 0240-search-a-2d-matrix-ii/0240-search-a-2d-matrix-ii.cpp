class Solution {
    bool binarySearch(int i,int target,vector<vector<int>>& matrix){
        int low = 0,high = matrix[0].size();
        while(low<=high){
            int mid = low + (high-low)/2;
            if(matrix[i][mid] == target){
                return true;
            }
            else if(matrix[i][mid] > target){
                high = mid-1;
            }else{
                low =  mid+1;
            }
        }

      return false;
    }
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size(),m = matrix[0].size();

        bool ans = false;

        for(int i=0;i<n;i++){
            if(matrix[i][0]<=target and target<=matrix[i][m-1]){
                ans |= binarySearch(i,target,matrix);
            }
        }

        return ans;
    }
};