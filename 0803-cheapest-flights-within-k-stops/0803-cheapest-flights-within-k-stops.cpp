class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        //to find the shortest distance we will be using Dijkstra.The only thing to know is to stop when you reach the no of steps to be k:
        unordered_map<int,vector<pair<int,int>>>adj;

        for(auto &it: flights){
            int u=it[0],v=it[1],w=it[2];
            adj[u].push_back({v,w});
        }

        vector<int>distance(n,1e9);

        distance[src] = 0;

        queue<pair<int,int>>q;

        q.push({src,0});

        int stops = 0;

        while(!q.empty() and stops <= k){
            int size = q.size();

            for(int i=0;i<size; i++){
                auto [par_node,par_dist] = q.front();
                q.pop();


                for(auto &child: adj[par_node]){
                    int node = child.first;

                    int edgeWeight = child.second;

                    if(edgeWeight + par_dist < distance[node]){
                        distance[node] = edgeWeight + par_dist;

                        q.push({node,distance[node]});
                    }
                }

               
            }

            stops++;
        }

        return (distance[dst] == 1e9 ? -1 : distance[dst]);
    }
};