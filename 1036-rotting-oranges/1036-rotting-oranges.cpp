class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n  = grid.size(), m= grid[0].size();
        int fresh = 0;

        queue<pair<int,int>>q;

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j] == 1){
                    fresh++;
                }else if(grid[i][j] == 2){
                    q.push({i,j});
                }
            }
        }

        if(fresh == 0) return 0;

        int rotten = 0;

        int t = 0;

        vector<pair<int,int>>directions = {{-1,0},{1,0},{0,-1},{0,1}};

        auto isValid =[&](int a,int b)->bool{
            return a>=0 and a<n and b>=0 and b<m;
        };

        while(!q.empty()){

            int size = q.size();

            bool huaKya = false;

            for(int i=0;i<size;i++){

                auto [a,b] = q.front();
                q.pop();

                for(auto &[x,y] : directions){
                    int nx = x + a;
                    int ny = y + b;

                    if(isValid(nx,ny) and grid[nx][ny] == 1){
                        rotten ++;
                        huaKya = true;
                        grid[nx][ny] = 2;
                        q.push({nx,ny});
                    }
                }
 
            }

            if(huaKya){
               t++;
            }
 
        }

        if(rotten != fresh){
            return -1;
        }


        return t;


    }
};