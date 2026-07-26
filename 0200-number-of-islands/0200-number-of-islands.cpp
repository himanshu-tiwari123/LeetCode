class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size() , m =grid[0].size();
        vector<vector<bool>>visited(n,vector<bool>(m, false));

        queue<pair<int,int>>q;

        int cnt  = 0;

        auto bfs = [&](auto &bfs, int i,int j)->void{
            visited[i][j] = true;
            q.push({i,j});

            auto isValid =[&](int i,int j){
                return i>=0 and i<n and j>=0 and j<m;
            };


            vector<pair<int,int>>directions = {{-1,0},{1,0},{0,1},{0,-1}};

            while(!q.empty()){
                auto [i,j] = q.front();
                q.pop();

                for(auto &it: directions){
                    int nx = i + it.first;
                    int ny = j + it.second;

                    if(isValid(nx,ny) and !visited[nx][ny] and grid[nx][ny]=='1'){
                        visited[nx][ny] = true;
                        q.push({nx,ny});
                    }
                }


            }
        };

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!visited[i][j] and grid[i][j]=='1'){
                    bfs(bfs,i,j);
                    cnt++;
                }
            }
        }


        return cnt;
    }
};