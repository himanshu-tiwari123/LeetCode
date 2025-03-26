class Solution {
    int count=0;
    bool isPossible(int start,int end,int x){
        int diff = abs(end-start);

        if((diff%x)==0){
            count += (diff/x);
            return true;
        }

        return false;

    }
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        int n = grid.size(),m=grid[0].size();

        vector<int>res;

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                res.push_back(grid[i][j]);
            }
        }

        sort(res.begin(),res.end());

        int median_index = (m*n)/2;

        int median_value = res[median_index];

        for(int i=0;i<(m*n);i++){
            int curr_value = res[i];

            if(!isPossible(curr_value,median_value,x)){

                return -1;
            }
            
        }

        return count;


    }
};