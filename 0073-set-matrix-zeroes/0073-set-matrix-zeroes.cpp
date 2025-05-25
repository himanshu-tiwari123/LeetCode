class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int n = matrix.size(),m=matrix[0].size();
        bool has_row_zeroes= false,has_col_zeroes=false;
        for(int i=0;i<n;i++){
           if(matrix[i][0] == 0){
            has_col_zeroes= true;
           }
        }

        for(int j=0;j<m;j++){
           if(matrix[0][j] == 0){
            has_row_zeroes= true;
           }
        }

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(matrix[i][j]==0){
                    matrix[i][0] = 0;
                    matrix[0][j]= 0;
                }
            }
        }

        for(int i=1;i<n;i++){
            for(int j=1;j<m;j++){
                if(matrix[i][0] ==0 or matrix[0][j] == 0){
                    matrix[i][j] = 0;
                }
            }
        }

        if(has_col_zeroes){
            for(int i=0;i<n;i++){
                matrix[i][0] =0;
            }
        }

        if(has_row_zeroes){
            for(int j=0;j<m;j++){
                matrix[0][j]=0;
            }
        }
}
};