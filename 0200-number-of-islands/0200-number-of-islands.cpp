class DSU{
    public:
    vector<int>parent;
    vector<int>rank;

    DSU(int n){
        parent.resize(n);
        rank.resize(n,0);

        for(int i=0;i<n;i++){
            parent[i] = i;
        }
    }

    int findParent(int a){
        if(a == parent[a]) return a;

        return parent[a] = findParent(parent[a]);
    }

    bool Union(int a, int b){
        int par_a = findParent(a);
        int par_b = findParent(b);

        if(par_a == par_b) return false;

        if(rank[par_a] < rank[par_b]){
            parent[par_a] = par_b;
        }else if(rank[par_b] < rank[par_a]){
            parent[par_b] = par_a; 
        }else{
            parent[par_a] = par_b;
            rank[par_b]++;
        }

        return true;
    }

};




class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size() , m =grid[0].size();

        DSU dsu(n*m);

        //We need to flatten the 2D grid to 1D to apply the DSU:
        int islands = 0;

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j] == '1') islands++;
            }
        }

        vector<pair<int,int>>directions = {{-1,0},{1,0},{0,-1},{0,1}};

        auto isValid = [&](int i,int j)->bool{
            return i>=0 and i<n and j>=0 and j<m;
        };

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j] == '1'){
                    int curr_pos = i*m + j;

                    for(auto &it: directions){
                        int nx = i+it.first;
                        int ny = j + it.second;

                        int new_pos = nx * m + ny;

                        if(isValid(nx,ny) and grid[nx][ny]=='1'){

                            if(dsu.Union(curr_pos,new_pos)){
                                islands--;
                            }

                        } 
                    }

                }
            }
        }
        


        return islands;
    }
};