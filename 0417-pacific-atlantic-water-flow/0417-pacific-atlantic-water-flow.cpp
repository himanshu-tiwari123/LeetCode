class Solution {
    bool isValid(int i,int j,vector<vector<int>>& heights){
        int n = heights.size(), m= heights[0].size();

        return i>=0 and i<n and j>=0 and j<m;
    }
    void bfs(int i,int j,vector<vector<bool>>&visited,vector<vector<int>>& heights){
        visited[i][j] = true;
        queue<pair<int,int>>q;
        q.push({i,j});

        vector<pair<int,int>>directions = {{-1,0},{1,0},{0,1},{0,-1}};

        while(!q.empty()){
            auto [i,j] = q.front();
            q.pop();
           
            for(auto &it: directions){
                int x = i + it.first;
                int y = j + it.second;


                if(isValid(x,y,heights) and !visited[x][y] and heights[x][y] >= heights[i][j]){
                    visited[x][y] = true;
                    q.push({x,y});
                }
            }

        }
    }
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int n = heights.size(),m=heights[0].size();

        vector<vector<bool>>vis1(n,vector<bool>(m,false));
        vector<vector<bool>>vis2(n,vector<bool>(m,false));

        for(int i=0;i<n;i++){
            if(!vis1[i][0]){
                bfs(i,0,vis1,heights);
            }
        
            if(!vis2[i][m-1]){
                bfs(i,m-1,vis2,heights);
            }

           
        }

        for(int j=0;j<m;j++){
            if(!vis1[0][j]){
                bfs(0,j,vis1,heights);
            }
        
            if(!vis2[n-1][j]){
                bfs(n-1,j,vis2,heights);
            }

           
        }

        vector<vector<int>>res;


        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(vis1[i][j] and vis2[i][j]){
                    res.push_back({i,j});
                }
            }
        }


        return res;
    }
};