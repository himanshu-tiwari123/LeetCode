class Solution {
    
public:
    int shortestPath(vector<vector<int>>& grid, int k) {
        int n = grid.size() , m = grid[0].size();
        //We are asked for shortest path and also we can traverse in all the 4 directions,so we need to use BFS for this purpose.

        queue<tuple<int,int,int,int>>q;

        q.push({0,0,0,k});

        vector<pair<int,int>>directions = {{-1,0},{1,0},{0,-1},{0,1}};

        vector<vector<vector<bool>>>visited(n,vector<vector<bool>>(m,vector<bool>(k+1,false)));

        visited[0][0][k] = true;

        

        auto isValid = [&](int x, int y)->bool{
            return x>=0 and x<n and y>=0 and y<m;
        };

        while(!q.empty()){

            auto [x,y,steps,k] = q.front();
            q.pop();

            

            if(x==n-1 and y==m-1){
                return steps;
            }


            for(auto &it: directions){
                int nx = x + it.first;
                int ny = y + it.second;

                if(isValid(nx,ny) and !visited[nx][ny][k]){
                    if(grid[nx][ny] == 0){
                        visited[nx][ny][k] = true;
                        q.push({nx,ny,steps+1,k});
                    }else{
                        if(k>0){
                            visited[nx][ny][k] = true;
                            q.push({nx,ny,steps+1,k-1});
                        }else{
                            continue;
                        }
                    }
                }
            }
 
        }

        return -1;
        
    }
};