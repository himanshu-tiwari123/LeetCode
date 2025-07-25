class Solution {
    bool isValid(int i,int j,vector<vector<int>>& grid){
        int n = grid.size(), m = grid[0].size();
        return ((i>=0 and i<n) and (j>=0 and j<m));
    }
    void bfs(int i,int j,vector<vector<bool>>&visited,vector<vector<int>>& grid){
        visited[i][j] = true;
        queue<pair<int,int>>q;
        q.push({i,j});

        while(!q.empty()){
            auto [r,c] = q.front();
            q.pop();

            vector<pair<int,int>>directions = {{-1,0},{1,0},{0,-1},{0,1}};

            for(auto &it : directions){
                int nr = it.first + r;
                int nc = it.second + c;

                if(isValid(nr,nc,grid) and !visited[nr][nc] and grid[nr][nc]==1){
                    visited[nr][nc] = 1;
                    q.push({nr,nc});
                }
            }
        }
    }
public:
    int minDays(vector<vector<int>>& grid) {
        int n = grid.size(),m = grid[0].size();

        vector<vector<bool>>visited(n,vector<bool>(m,false));
        int connected_components = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1 and !visited[i][j]){
                    bfs(i,j,visited,grid);
                    connected_components++;
                }
            }
        }

        if(connected_components==0 || connected_components > 1){
            return 0;
        }

        for(int r=0;r<n;r++){
            for(int c=0;c<m;c++){

                int connected_components = 0;
                vector<vector<bool>>visited(n,vector<bool>(m,false));
                
            if(grid[r][c]==1){

                grid[r][c] = 0;

                for(int i=0;i<n;i++){
                    for(int j=0;j<m;j++){
                        if(grid[i][j]==1 and !visited[i][j]){
                        bfs(i,j,visited,grid);
                        connected_components++;
                        }
                    }
                }

                if(connected_components==0 || connected_components > 1){
                    return 1;
                }

                grid[r][c] = 1;
            }

            }
        }

        return 2;

    }
};