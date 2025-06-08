class Solution {
    char dfs(char node,char &min_char,unordered_map<char,vector<char>>&adj,vector<bool>&visited){
        visited[node-'a'] = true;
        min_char = min(min_char,node);

        for(auto &child : adj[node]){
            if(!visited[child-'a']){
                dfs(child,min_char,adj,visited);
            }
        }

        return min_char;

    }
public:
    string smallestEquivalentString(string s1, string s2, string baseStr) {
        int n = s1.size();
        unordered_map<char,vector<char>>adj;

        for(int i=0;i<n;i++){
            char c1 = s1[i],c2 = s2[i];
            adj[c1].push_back(c2);
            adj[c2].push_back(c1);
        }

        string ans= "";

        for(int i=0;i<baseStr.size();i++){
            vector<bool>visited(26,false);
            char min_char = dfs(baseStr[i],baseStr[i],adj,visited);
            ans += min_char;
        }

        return ans;
    }
};