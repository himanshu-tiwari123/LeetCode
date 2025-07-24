class Solution {
    int timer= 0;
    void dfs(int node,int parent,vector<int>&nums,vector<int>&inTime,vector<int>&outTime,vector<int>&subtreeXor,unordered_map<int,vector<int>>&adj){
        inTime[node] = timer++;
        subtreeXor[node] = nums[node];

        for(auto &child : adj[node]){
            if(child != parent){
                dfs(child,node,nums,inTime,outTime,subtreeXor,adj);
                subtreeXor[node] ^= subtreeXor[child];

            }
        }

        outTime[node] = timer++;
    }

    bool isAncestor(int a,int b,vector<int>&inTime,vector<int>&outTime){
       return (inTime[a] < inTime[b] && outTime[a] > outTime[b]);
    }

    int findAns(int a,int b,int c){
        int maxi = max({a,b,c});
        int mini = min({a,b,c});

        return maxi - mini;
    }
public:
    int minimumScore(vector<int>& nums, vector<vector<int>>& edges) {
        int  n = nums.size();
        
        unordered_map<int,vector<int>>adj;

        for(auto &it:edges){
            int u = it[0],v=it[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<int>subtreeXor(n,0),inTime(n,0),outTime(n,0);
        dfs(0,-1,nums,inTime,outTime,subtreeXor,adj);

        int ans = INT_MAX;

        for(int u=1;u<n;u++){
            for(int v=u+1;v<n;v++){
                int xor1,xor2,xor3;

                if(isAncestor(u,v,inTime,outTime)){

                    //u is parent of v:
                    xor1 = subtreeXor[v];
                    xor2 = subtreeXor[u]^subtreeXor[v];
                    xor3 = subtreeXor[0]^xor1^xor2;

                }else if(isAncestor(v,u,inTime,outTime)){
                    xor1 = subtreeXor[u];
                    xor2 = subtreeXor[v]^subtreeXor[u];
                    xor3 = subtreeXor[0]^xor1^xor2;
                }else{
                    xor1 = subtreeXor[v];
                    xor2 = subtreeXor[u];
                    xor3 = subtreeXor[0]^xor1^xor2;
                }

                ans = min(ans, findAns(xor1,xor2,xor3));
            }
        }

        return ans;


    }
};