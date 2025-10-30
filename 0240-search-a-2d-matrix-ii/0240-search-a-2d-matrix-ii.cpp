class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size() , m = matrix[0].size();

        int l = 0,r = m-1;

        if(matrix[l][r] == target) return true;

        //I am starting from top-right cell of the matrix.If the values are less so we move towards left else if the values are bigger we move down.If we go out of bounds we are done,we were not able to find this else if we found we return true:

        //note we have placed l as 0 so it will move downward:

        while(l<n and r>=0){
            if(matrix[l][r] == target){
                return true;
            }else if(matrix[l][r] > target){
                r--; // we move towrds left;
            }else {
                l++;
            }
        }

        

        return false;
    }
};