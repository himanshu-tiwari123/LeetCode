class Solution {

    vector<pair<int,int>>directions = {{-1,0},{1,0},{0,1},{0,-1}};
    bool isValid(int i,int j,vector<vector<int>>& grid){
        int n = grid.size(),m=grid[0].size();

        if(i>=0 and i<n and j>=0 and j<m){
            return true;
        }

        return false;
    }

    int dfs(int i,int j,vector<vector<int>>& grid){

        // if(!isValid(i,j,grid) || grid[i][j] == 0){
        //     return 0;
        // }

        int curr_cost = grid[i][j];

        grid[i][j] = 0;

        int neighbour_cost = 0;

        for(auto &[x,y] : directions){
            int nx = i + x;
            int ny = j + y;

            if(isValid(nx,ny,grid) and grid[nx][ny] !=0){
              neighbour_cost = max(neighbour_cost,dfs(nx,ny,grid));
            }
        }

        grid[i][j] = curr_cost;

        return curr_cost + neighbour_cost;
    }

    
public:
    int getMaximumGold(vector<vector<int>>& grid) {
        int n = grid.size(), m= grid[0].size();

        int max_cnt = 0;

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                   if(grid[i][j] !=0){
                    max_cnt = max(max_cnt, dfs(i,j,grid));
                   }
            }
        }

        return max_cnt;
       
    
    }
};