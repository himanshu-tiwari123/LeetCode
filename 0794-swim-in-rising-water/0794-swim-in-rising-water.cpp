class Solution {

    bool isValid(int i,int j,vector<vector<int>>& grid){
        int n = grid.size();

        return i>=0 and i<n and j>=0 and j<n;
    }
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        
        priority_queue<tuple<int,int,int>,vector<tuple<int,int,int>>,greater<tuple<int,int,int>>>pq;


        vector<vector<int>>distance(n,vector<int>(n,1e9));

        distance[0][0] = grid[0][0];

        pq.push({grid[0][0],0,0});

        vector<pair<int,int>>directions = {{-1,0},{1,0},{0,-1},{0,1}};

        // int curr_time = INT_MIN;

        while(!pq.empty()){
            auto [t,i,j] = pq.top();
            pq.pop();

            if(i==n-1 and j==n-1){
                return t;
            }
            
            
            for(auto &it: directions){
                int x = i + it.first;
                int y = j + it.second;

                if(isValid(x,y,grid)){
                    int curr_time = max(t,grid[x][y]);
                    
                    if(curr_time < distance[x][y]){
                        distance[x][y] = curr_time;

                        pq.push({distance[x][y],x,y});
                    }
                }
            }
        }

        return distance[n-1][n-1];
    }
};