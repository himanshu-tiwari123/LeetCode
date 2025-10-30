class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size() , m = matrix[0].size();

        // we need to use some kind of logic for this man,but I am unable to get how to do this man!!!

        int l = 0,r = (m*n)-1;

        for(int i=0;i<n;i++){
            auto lb = lower_bound(matrix[i].begin(),matrix[i].end(),target)-matrix[i].begin();
            if((lb < m ) and (matrix[i][lb] == target) ){
                return true;
            }
        }

        return false;
    }
};