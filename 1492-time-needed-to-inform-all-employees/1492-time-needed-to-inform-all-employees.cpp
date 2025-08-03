class Solution {
    int max_time = 0;
    void dfs(int node,int parent,int total_time,vector<int>&informTime,unordered_map<int,vector<int>>&adj){
       
        total_time += informTime[node];

       for(auto &child : adj[node]){
           if(child != parent){
              dfs(child,node,total_time,informTime,adj);
           }
       }

       max_time = max(max_time,total_time);

      
    }
public:
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        unordered_map<int,vector<int>>adj;

        for(int i=0;i<manager.size();i++){
            adj[manager[i]].push_back(i);
        }

        int total_time = 0;

        dfs(headID,-1,total_time,informTime,adj);

        return max_time;
    }
};