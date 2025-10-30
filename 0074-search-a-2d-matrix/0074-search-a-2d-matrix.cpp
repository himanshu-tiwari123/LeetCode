class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        //we need to use binary Search man:

        int n =  matrix.size(), m= matrix[0].size();
        
        int l=0,r=(m*n)-1;

        while(l<=r){
            int mid = l + (r-l)/2;

            int i = (mid/m) ,j = (mid%m);

            if(matrix[i][j] == target){
                return true;
            }else if(matrix[i][j] < target){
                l = mid+1;
            }else{
                r = mid-1;
            }

        }

        return false;

    }
};