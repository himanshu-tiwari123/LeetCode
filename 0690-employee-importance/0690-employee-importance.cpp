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
    int dfs(int node,int cnt,unordered_map<int,vector<int>>&adj,unordered_map<int,int>&importance){
        cnt = importance[node];

        for(auto &child: adj[node]){
            cnt += dfs(child,cnt,adj,importance);
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
        
        int imp = dfs(id,0,adj,importance);

        return imp;
    }
};