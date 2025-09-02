class Solution {
    vector<vector<int>>res;
    bool isValid(int i,int j,vector<vector<int>>&grid){
        int n=grid.size(),m = grid[0].size();

        return i>=0 and i<n and j>=0 and j<m;
    }

    void bfs(int i ,int j,vector<vector<bool>>&visited,vector<vector<int>>&grid){
        visited[i][j] = true;
        queue<pair<int,int>>q;
        q.push({i,j});

        vector<pair<int,int>>directions = {{-1,0},{1,0},{0,1},{0,-1}};

        while(!q.empty()){
            auto [i,j] = q.front();
            q.pop();

            for(auto &[x,y] : directions){
                int nx = i + x;
                int ny = j + y;

                if(isValid(nx,ny,grid) and !visited[nx][ny] and grid[nx][ny] >= grid[i][j]){
                    visited[nx][ny] = true;
                    q.push({nx,ny});
                }
            }
        }
    }
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int  n = heights.size() , m = heights[0].size();

        vector<vector<bool>>visitedPacific(n,vector<bool>(m,false));
        vector<vector<bool>>visitedAtlantic(n,vector<bool>(m,false));
        
        for(int j=0;j<m;j++){
           bfs(0,j,visitedPacific,heights);
           bfs(n-1,j,visitedAtlantic,heights);
        }

        for(int i=0;i<n;i++){
           bfs(i,0,visitedPacific,heights);
           bfs(i,m-1,visitedAtlantic,heights);
        }

        

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(visitedPacific[i][j] && visitedAtlantic[i][j]){
                    res.push_back({i,j});
                }

                
            }
        }

       return res;
    }
};