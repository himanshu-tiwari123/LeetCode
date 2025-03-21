class Solution {
public:vector<int>parent;
       vector<int>cost;
       
    vector<int> minimumCost(int n, vector<vector<int>>& edges, vector<vector<int>>& queries) {
       parent.resize(n,-1);
       
       for(int i=0;i<n;i++){
        parent[i]=i;
       }

       cost.resize(n,-1);
       vector<int>ans;

    //Step 1:First do union of the edges: 
       
        for(auto &edge:edges){
            Union(edge[0],edge[1]);
        }

    // Step 2:Now try to find the bitwise and of all the components:
        for(auto &edge:edges){
            int root = find(edge[0]);
            cost[root] &= edge[2];
        }

    //Step 3:Now try to find the answer to queries:

    for(auto &query :queries){
        int start = query[0];
        int end = query[1];
        //First check if they are connected or not:

        if(find(start)!=find(end)){
            //They are disconnected:
            ans.push_back(-1);
        }
        else{
            //They are connected:
            int root = find(start);
            ans.push_back(cost[root]);
        }
    }
        

    return ans;

    }

private:
    int find(int node){
       //Base Case:
        if(parent[node]==node){
           return node;
        }

       return parent[node] = find(parent[node]);
    }

    void Union(int node1,int node2){
        int root1 = find(node1);
        int root2 = find(node2);

        if(root1 != root2){
            parent[root2] = root1;
        }
    }
};