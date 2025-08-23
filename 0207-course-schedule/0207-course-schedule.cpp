class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        //topological sorting is used for DAG:
        unordered_map<int,vector<int>>adj;

        vector<int>indegree(numCourses,0);

        for(auto &it: prerequisites){
            int u = it[0],v=it[1];
            adj[v].push_back(u);
            indegree[u]++;
        }
        
        queue<int>q;

        for(int i=0;i<numCourses;i++){
            if(indegree[i] == 0){
                q.push(i);
            }
        }


        while(!q.empty()){
            int node = q.front();
            q.pop();

            for(auto &child: adj[node]){
               indegree[child]--;

                if(indegree[child] == 0){
                  q.push(child);
                }
            }
        }

        for(auto &it:indegree){
            if(it != 0){
                return false;
            }
        }

        return true;
    }
};