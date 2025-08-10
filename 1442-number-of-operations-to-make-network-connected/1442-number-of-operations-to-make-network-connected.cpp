class Solution {
    struct DSU{
        vector<int>parent,rank;

        DSU (int n){
          rank.resize(n,0);
          parent.resize(n);

          for(int i=0;i<n;i++){
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
                parent[par_v] = par_u;
            }else if(rank[par_v] > rank[par_u]){
                parent[par_u] = par_v;
            }else{
                parent[par_v] = par_u;
                rank[par_u]++; 
            }
        }
    };
public:
    int makeConnected(int n, vector<vector<int>>& connections) {

        if(connections.size() < n-1){
            return -1; //cause to connect n different computers we need n-1 wires
        }

        DSU d(n);

        for(int i=0;i<connections.size();i++){
           int u = connections[i][0] , v = connections[i][1];
           d.UnionByRank(u,v);
        }
        int min_connections = 0;
        for(int i=0;i<n;i++){
            if(d.parent[i] == i){
              min_connections++;
            }
        }

        return min_connections-1;
    }
};