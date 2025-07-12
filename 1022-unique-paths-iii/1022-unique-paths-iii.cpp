class Solution {
    int m,n,ways=0;
    int empty_squares=0;
    bool isValid(int i,int j,vector<vector<int>>& grid){
        if((i>=0 and i<n) and (j>=0 and j<m)){
            return true;
        }

        return false;
    }
    void findAns(int i,int j,int cnt,vector<vector<bool>>&visited,vector<vector<int>>& grid){
        //Base Case:
        if(grid[i][j]==2 and cnt==empty_squares){
            ways++;
            return;
        }

        vector<pair<int,int>>directions = {{-1,0},{1,0},{0,-1},{0,1}};

        for(auto &it:directions){
            int new_x = i + it.first;
            int new_y = j + it.second;

            if(isValid(new_x,new_y,grid) and !visited[new_x][new_y] and grid[new_x][new_y]!=-1){
                visited[new_x][new_y] = true;
                cnt++;
                findAns(new_x,new_y,cnt,visited,grid);
                
                cnt--;
                visited[new_x][new_y] = false;


            }
        }



    }

public:
    int uniquePathsIII(vector<vector<int>>& grid) {
        n = grid.size(),m = grid[0].size();
        int start_x,start_y;

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j] == 0){
                   empty_squares++;
                }

                if(grid[i][j] == 1){
                    start_x = i;
                    start_y = j;
                }
            }
        }

        empty_squares++;//this is for the starting cell man:

        vector<vector<bool>>visited(n,vector<bool>(m,false));

        visited[start_x][start_y] = true;

        findAns(start_x,start_y,0,visited,grid);

        return ways;
    }
};