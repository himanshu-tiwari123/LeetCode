class Solution {
public:
//   bool visited[20][20][51][(1<<10)] = {};

    int minMoves(vector<string>& classroom, int energy) {
        int n = classroom.size() , m = classroom[0].size();

        int sx,sy,total_litter_cnt  = 0;
        int bitPos[n][m];

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(classroom[i][j] == 'S'){
                    sx = i, sy=j;
                }else if(classroom[i][j] == 'L'){
                    bitPos[i][j] = total_litter_cnt++;
                }
            }
        }

        struct State{
            int x,y,e,mask,moves;
        };

        
       vector<vector<vector<vector<int>>>>visited(n,vector<vector<vector<int>>>(m,vector<vector<int>>(energy+1, vector<int>(1<<total_litter_cnt, false))));

        visited[sx][sy][energy][0] = true;

        queue<State>q;

        q.push({sx,sy,energy,0,0});

        vector<pair<int,int>>directions = {{-1,0},{1,0},{0,1},{0,-1}};

        while(!q.empty()){
            auto state = q.front();
            q.pop();

            if(state.mask ==  ((1<<total_litter_cnt)-1)){
                return state.moves;
            }

            if(state.e == 0) continue;
            
            for(auto &it: directions){
                int nx = state.x + it.first;
                int ny = state.y + it.second;
            
                if(nx < 0 or nx >= n || ny < 0 or ny >= m) continue;

                    int ne = state.e - 1;
                    int nm = state.mask;

                    if(classroom[nx][ny] == 'X') continue;
                    else if(classroom[nx][ny] == 'R'){
                        ne = energy;
                    }else if(classroom[nx][ny] == 'L'){
                        nm |= (1<<bitPos[nx][ny]);
                    }


                    if(!visited[nx][ny][ne][nm]){
                        visited[nx][ny][ne][nm] = true;
                        q.push({nx,ny,ne,nm,state.moves+1});
                    }

            }

        }


        return -1;

    }
};