class Solution {
    #define ll long long
    const int modulo = 1e9+7;
    ll binExp(int base,int exponent){
        //Base Case:
        if(exponent ==0){
            return 1;
        }
        ll half = binExp(base,exponent/2);
        ll res = (half*half)%modulo;

        if(exponent%2 == 1){
            res = (res*base)%modulo;

        }
        return res;
    }
public:
    int assignEdgeWeights(vector<vector<int>>& edges) {
        unordered_map<int,vector<int>>adj;
        for(auto &it:edges){
            int u=it[0],v=it[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        int depth=0;
        vector<bool>visited(1e5+3,false);
        queue<int>q;
        q.push(1);
        visited[1] = true;
        while(!q.empty()){
            int size = q.size();
            for(int i=0;i<size;i++){
                int par_node = q.front();
                q.pop();
                bool haiKya = false;
                for(auto &it:adj[par_node]){
                   if(!visited[it]){
                      haiKya= true;
                       visited[it] = true;
                       q.push(it);
                    }
                }
            }

            ++depth;
            
        }
        cout<<depth<<"\n";
        ll ans = binExp(2,depth-2);

        return ans;
    }
};