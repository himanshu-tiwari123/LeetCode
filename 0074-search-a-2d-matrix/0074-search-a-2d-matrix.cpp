class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        //we need to use binary Search man:

        int n =  matrix.size(), m= matrix[0].size();

        //we can think of serializing the matrix man;

        vector<int>arr;

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
               arr.push_back(matrix[i][j]);


            }
        }

        //Now lets apply Bs;
        int low=0,high = arr.size()-1;

        while(low<= high){
            int mid = low + (high-low)/2;

            if(arr[mid] == target){
                return true;
            }else if(arr[mid] < target){
                low = mid+1;
            }else
            {
                high = mid-1;
            }
        }


        return false;


    }
};