class DSU{
    public:
    vector<int>parent,rank;

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


        if(par_a == par_b){
            return false;
        }


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
    int makeConnected(int n, vector<vector<int>>& connections) {

        DSU dsu(n);

        int extra_connections = 0;

        for(auto it : connections){
            int u = it[0] , v = it[1];
            if(! dsu.Union(u,v)){
                extra_connections++;
            }
        }

        int components = 0;

        for(int i=0;i<n;i++){
            if(dsu.parent[i] == i){
                components++;
            }
        }


        return (extra_connections >= components-1 ? components-1 : -1);
        
    }
};