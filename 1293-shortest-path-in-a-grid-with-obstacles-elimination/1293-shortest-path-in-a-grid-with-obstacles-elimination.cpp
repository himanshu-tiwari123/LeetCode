class Solution {
    
public:
    int shortestPath(vector<vector<int>>& grid, int k) {
        int n = grid.size(), m = grid[0].size();

        // Early optimization
        if (k >= n + m - 2) return n + m - 2;

        queue<tuple<int,int,int,int>> q;
        q.push({0,0,0,k});

        vector<pair<int,int>> directions = {{-1,0},{1,0},{0,-1},{0,1}};

        vector<vector<vector<bool>>> visited(
            n, vector<vector<bool>>(m, vector<bool>(k+1,false))
        );

        visited[0][0][k] = true;

        auto isValid = [&](int x, int y)->bool{
            return x>=0 && x<n && y>=0 && y<m;
        };

        while(!q.empty()){

            auto [x,y,steps,rem] = q.front(); // renamed k → rem
            q.pop();

            if(x == n-1 && y == m-1){
                return steps;
            }

            for(auto &it: directions){
                int nx = x + it.first;
                int ny = y + it.second;

                if(!isValid(nx,ny)) continue;

                // Case 1: empty cell
                if(grid[nx][ny] == 0){
                    if(!visited[nx][ny][rem]){
                        visited[nx][ny][rem] = true;
                        q.push({nx,ny,steps+1,rem});
                    }
                }
                // Case 2: obstacle
                else if(rem > 0){
                    if(!visited[nx][ny][rem-1]){
                        visited[nx][ny][rem-1] = true; // ✅ FIXED
                        q.push({nx,ny,steps+1,rem-1});
                    }
                }
            }
        }

        return -1;
    }
};