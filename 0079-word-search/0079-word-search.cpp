class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        int n  = board.size() , m = board[0].size();

        auto dfs = [&](auto &dfs, int i,int j,string s, vector<vector<bool>>&visited)->bool{
            if(i<0 || i>=n || j<0 || j>=m) return false;

            if(word[s.size()] != board[i][j]) return false;

            if(visited[i][j]) return false;

            s += board[i][j];

            visited[i][j] = true;

            if(s == word){
               return true;
            }

            bool ans=dfs(dfs,i+1,j,s,visited) ||
                    dfs(dfs,i,j+1,s,visited) ||
                    dfs(dfs,i-1,j,s,visited) ||
                    dfs(dfs,i,j-1,s,visited);

            visited[i][j] = false;

            return ans;
        };

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                string s = "";
                vector<vector<bool>>visited(n,vector<bool>(m, false));

                if(dfs(dfs,i,j,s,visited)){
                    return true;
                }
            }
        }


        return false;


    }
};