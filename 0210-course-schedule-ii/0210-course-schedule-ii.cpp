class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int>ans;

        vector<int>indegree(numCourses,0);

        unordered_map<int,vector<int>>adj;

        for(auto &it: prerequisites){
            int u = it[0], v= it[1];

            adj[v].push_back(u);

            indegree[u] ++;
        }

        queue<int>q;

        for(int i=0;i<numCourses;i++){
            if(indegree[i] == 0){
                q.push(i);
                ans.push_back(i);
            }
        }

        while(!q.empty()){
            int node = q.front();
            q.pop();

            for(auto &child : adj[node]){
                indegree[child] --;

                if(indegree[child] == 0){
                    q.push(child);
                    ans.push_back(child);
                }
            }
        }
        
        if(ans.size() == numCourses){
            return ans;
        }else{
            return {};
        }

    }
};