class Solution {
    double bfs(string &u,string &v,unordered_map<string,vector<pair<string,double>>>&adj){
        queue<pair<string,double>>q;
        q.push({u,1.0});

        unordered_map<string,int>visited;
        visited[u]++;

        while(!q.empty()){
            auto [s,res] = q.front();
            q.pop();

            if(s==v){
                return res;
            }

            for(auto &it: adj[s]){
                string child = it.first;
                double edgeWeight = it.second;

                if(visited.find(child) == visited.end()){
                    visited[child]++;
                    double newAns = (res*edgeWeight);
                    q.push({child,newAns});
                }
            }
        }

        return -1.0;
    }
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {

        int n = values.size();
        unordered_map<string,vector<pair<string,double>>>adj;

        vector<double>ans;

        for(int i=0;i<n;i++){
            string u = equations[i][0],v=equations[i][1];
            double w = values[i];
            adj[u].push_back({v,w});
            adj[v].push_back({u,(1.0/w)});
        }

        for(auto &it: queries){
            string u=it[0],v=it[1];

            if(adj[u].size()==0 and adj[v].size()==0){
                ans.push_back(-1.0);
                continue;
            }

            double res = bfs(u,v,adj);

            ans.push_back(res);
            
        }

        return ans;

    }
};