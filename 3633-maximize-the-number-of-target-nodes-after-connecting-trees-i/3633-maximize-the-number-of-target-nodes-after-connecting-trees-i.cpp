class Solution {
    int bfs(int node,unordered_map<int,vector<int>>&adj,int cnt,vector<bool>&visited,int k){
        visited[node] = true;
        queue<pair<int,int>>q;
        q.push({node,k});

        while(!q.empty()){
            int par_node = q.front().first;
            int depth = q.front().second;
            q.pop();

            cnt++;
            if(depth == 0){
                continue;
            }

            for(auto &child: adj[par_node]){
                if(!visited[child]){
                    visited[child] = true;
                    q.push({child,depth-1});
                }
            }
        }

        return cnt;
    }
public:
    vector<int> maxTargetNodes(vector<vector<int>>& edges1, vector<vector<int>>& edges2, int k) {
        ios_base::sync_with_stdio(false);
        cin.tie(0);
        cout.tie(0);
        unordered_map<int,vector<int>>adj1,adj2;

        for(auto &it:edges1){
            adj1[it[0]].push_back(it[1]);
            adj1[it[1]].push_back(it[0]);
        }
        for(auto &it:edges2){
            adj2[it[0]].push_back(it[1]);
            adj2[it[1]].push_back(it[0]);
        }
        
        int n = edges1.size()+1,m = edges2.size()+1;

        vector<int>ans;
        if(k==0){
            for(int i=0;i<n;i++){
                ans.push_back(1);

            }

            return ans;
        }

        //precompute for tree 2:
        int cnt2 = 0;

        for(int j=0;j<m;j++){
            vector<bool>visited(m+1,false);
            cnt2 = max(cnt2,bfs(j,adj2,0,visited,k-1));
        }
        

        for(int i=0;i<n;i++){
            vector<bool>visited(n+1,false);
            int cnt1 = bfs(i,adj1,0,visited,k);
            ans.push_back(cnt1+cnt2);
        }

        return ans;

    }
};