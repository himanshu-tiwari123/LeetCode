class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int  n = matrix.size(),m=matrix[0].size();
        int low = 0,high = m*n-1;

        while(low<=high){
            int mid = low+(high-low)/2;

            //Now we need to find row and col of mid:
            int row = mid/m, col = mid%m;

            if(matrix[row][col] == target){
                return true;
            }
            else if(matrix[row][col]  > target){
                high = mid-1;
            }
            else{
                low = mid+1;
            }
        }

        return false;
    }
};