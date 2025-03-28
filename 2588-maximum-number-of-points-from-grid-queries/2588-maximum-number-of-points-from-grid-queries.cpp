class Solution {
    vector<int>ans;
    vector<vector<bool>>visited;
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>query;

    bool isValid(int i,int j,vector<vector<int>>& grid){
        if((i>=0 and i<grid.size()) and (j>=0 and j<grid[0].size())){
            return true;
        }
        return false;
    }

    void bfs(vector<vector<int>>& grid){
        priority_queue<tuple<int,int,int>,vector<tuple<int,int,int>>,greater<tuple<int,int,int>>>pq;
        pq.emplace(grid[0][0],0,0);
        visited[0][0] = true;
        int count = 0;

        while(!query.empty()){
            auto [k,index] = query.top();
            query.pop();

          while(!pq.empty()){
            auto [val,i,j] = pq.top();

            if(val >= k){
                break;
            }

            pq.pop();
            count++;

            vector<pair<int,int>>directions = {{-1,0},{1,0},{0,-1},{0,1}};

            for(auto &it:directions){
                int x = it.first+i;
                int y = it.second+j;

                if(isValid(x,y,grid) and !visited[x][y]){
                    visited[x][y] = true;
                    pq.emplace(grid[x][y],x,y);
                }
            }
            }

            ans[index] = count;
            
        }
}

public:
    vector<int> maxPoints(vector<vector<int>>& grid, vector<int>& queries) {
        int n = grid.size(),m=grid[0].size();
        

        for(int i=0;i<queries.size();i++){
            query.push({queries[i],i});
        }

        ans.resize(query.size(),0);

        visited.resize(n,vector<bool>(m,false));

       bfs(grid);
        

        return ans;
    }
};