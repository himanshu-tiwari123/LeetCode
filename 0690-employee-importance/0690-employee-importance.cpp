/*
// Definition for Employee.
class Employee {
public:
    int id;
    int importance;
    vector<int> subordinates;
};
*/

class Solution {
    int bfs(int node,int cnt,unordered_map<int,vector<int>>&adj,unordered_map<int,int>&importance){
        queue<int>q;
        q.push(node);

        while(!q.empty()){
            int par_node  = q.front();q.pop();
            cnt += importance[par_node];

            for(auto &child : adj[par_node]){
                q.push(child);
            }
        }

        return cnt;
    }
public:
    int getImportance(vector<Employee*> employees, int id) {
        unordered_map<int,vector<int>>adj;
        unordered_map<int,int>importance;

        for(int i=0;i<employees.size();i++){
            int ID = employees[i]->id;
            int imp = employees[i]->importance;
            vector<int>v(employees[i]->subordinates);
            importance[ID] = imp;
            if(!v.empty()){
                for(auto &it:v){
                    adj[ID].push_back(it);
                }
            }
        }
        
        int imp = bfs(id,0,adj,importance);

        return imp;
    }
};