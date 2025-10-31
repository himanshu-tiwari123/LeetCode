class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n = grid.size() ,m = grid[0].size();
        int max_area = 0;

        vector<vector<bool>>visited(n,vector<bool>(m,false));

        vector<pair<int,int>>directions = {{-1,0},{1,0},{0,1},{0,-1}};

        auto isValid =[&](int i,int j)->bool{
            return i>=0 and i<n and j>=0 and j<m;
        };

        auto bfs=[&](int i,int j)->int{
            visited[i][j] = true;
            queue<pair<int,int>>q;

            q.push({i,j});

            int curr_area = 1;

            while(!q.empty()){

                auto [i,j] = q.front();q.pop();

                for(auto &it: directions){

                    int nx = i + it.first;
                    int ny = j + it.second;

                    if(isValid(nx,ny) and !visited[nx][ny] and grid[nx][ny] == 1){
                        visited[nx][ny] = true;
                        curr_area ++;
                        q.push({nx,ny});
                    }
 
                }

            }

            return curr_area;
        };

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){

                if(!visited[i][j] and grid[i][j]==1){
                    max_area = max(max_area, bfs(i,j));
                }
              
            }
        }


        return max_area;

    }



};