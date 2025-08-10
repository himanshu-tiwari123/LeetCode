class Solution {
    struct DSU{
        vector<int>parent,rank;

        DSU(int n){
            rank.resize(n+1,0);

            parent.resize(n+1);

            for(int i=0;i<=n;i++){
                parent[i] = i;
            }
        }

        int findParent(int u){
            if(u == parent[u]){
                return u;
            }
            return parent[u] = findParent(parent[u]);
        }

        void UnionByRank(int u,int v){
            int par_u = findParent(u);
            int par_v = findParent(v);

            if(par_u == par_v){
                return;
            }

            if(rank[par_u] > rank[par_v]){
                parent[par_v]  = par_u;
            }else if(rank[par_v] > rank[par_u]){
                parent[par_u]  = par_v;
            }else{
                parent[par_v]  = par_u;
                rank[par_u]++;
            }
        }
    };
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size(), m = isConnected[0].size();
        
        int provinces = 0;

        DSU d(n);

        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(isConnected[i][j]==1){
                    d.UnionByRank(i+1,j+1);
                }
            }
        }

        for(int i=1;i<=n;i++){
            if(d.parent[i] == i){
                provinces++;
            }
        }

        return provinces;
    }
};