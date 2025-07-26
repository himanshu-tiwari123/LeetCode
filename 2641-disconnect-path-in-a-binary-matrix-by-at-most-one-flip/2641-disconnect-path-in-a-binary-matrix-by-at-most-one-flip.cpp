class Solution {
    int n,m;
    
    bool dfs(int i,int j,vector<vector<int>>& grid){
        if(i>=n or j>=m or grid[i][j]==0){
            return false;
        }

        if(i==n-1 and j==m-1){
            return true;
        }

        //the visited paths are marked to be zero;
        grid[i][j] = 0;
        
        return dfs(i+1,j,grid) || dfs(i,j+1,grid);
    }
public:
    bool isPossibleToCutPath(vector<vector<int>>& grid) {
        n = grid.size(), m= grid[0].size();
        
        if(!dfs(0,0,grid)){
            //no path exists from (0,0) to (m-1,n-1);
            return true;
        }

        //restore grid[0][0];
        grid[0][0] = 1;

        return !dfs(0,0,grid);


    }
};